#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

#define MAX_ITER 1000
#define TOL 1e-12  // Increased precision
#define SHIFT_STRATEGY_WILKINSON 1
#define SHIFT_STRATEGY_RAYLEIGH 2

typedef struct {
    double** data;
    int rows;
    int cols;
} Matrix;

// Function declarations
Matrix* createMatrix(int rows, int cols);
void destroyMatrix(Matrix* m);
void copyMatrix(Matrix* dest, Matrix* src);
double wilkinsonShift(Matrix* A, int n);
double rayleighShift(Matrix* A, int n);
void givensRotation(Matrix* A, int p, int q, int i, int k);
int deflationPossible(Matrix* A, int n, double tol);

// Main QR Algorithm implementation
void improvedQR(Matrix* A, double* eigenvalues, int shiftStrategy) {
    int n = A->rows;
    Matrix* H = createMatrix(n, n);
    copyMatrix(H, A);
    
    int iterCount = 0;
    int deflateSize = n;
    
    while (deflateSize > 1 && iterCount < MAX_ITER) {
        // Check if deflation is possible
        if (deflationPossible(H, deflateSize, TOL)) {
            eigenvalues[deflateSize-1] = H->data[deflateSize-1][deflateSize-1];
            deflateSize--;
            continue;
        }
        
        // Compute shift based on strategy
        double shift;
        if (shiftStrategy == SHIFT_STRATEGY_WILKINSON) {
            shift = wilkinsonShift(H, deflateSize);
        } else {
            shift = rayleighShift(H, deflateSize);
        }
        
        // Apply shift
        for (int i = 0; i < deflateSize; i++) {
            H->data[i][i] -= shift;
        }
        
        // QR decomposition using Givens rotations
        for (int j = 0; j < deflateSize - 1; j++) {
            for (int i = j + 1; i < deflateSize; i++) {
                if (fabs(H->data[i][j]) > TOL) {
                    givensRotation(H, j, i, j, deflateSize);
                }
            }
        }
        
        // Reconstruct matrix and add shift back
        for (int i = 0; i < deflateSize; i++) {
            H->data[i][i] += shift;
        }
        
        if (++iterCount > MAX_ITER) {
            printf("Warning: Maximum iterations reached. Results may not be accurate.\n");
            break;
        }
    }
    
    // Extract remaining eigenvalues
    for (int i = 0; i < deflateSize; i++) {
        eigenvalues[i] = H->data[i][i];
    }
    
    destroyMatrix(H);
}

// Wilkinson shift computation
double wilkinsonShift(Matrix* A, int n) {
    double a = A->data[n-2][n-2];
    double b = A->data[n-2][n-1];
    double c = A->data[n-1][n-1];
    double d = (a - c) / 2.0;
    double sign = (d >= 0) ? 1.0 : -1.0;
    return c - sign * b * b / (fabs(d) + sqrt(d * d + b * b));
}

// Rayleigh shift computation
double rayleighShift(Matrix* A, int n) {
    return A->data[n-1][n-1];
}

// Givens rotation implementation
void givensRotation(Matrix* A, int p, int q, int i, int k) {
    double app = A->data[p][i];
    double aqq = A->data[q][i];
    double r = sqrt(app * app + aqq * aqq);
    
    if (r < TOL) return;  // Skip if rotation is unnecessary
    
    double c = app / r;
    double s = -aqq / r;
    
    // Apply rotation to rows
    for (int j = i; j < k; j++) {
        double tmp = c * A->data[p][j] - s * A->data[q][j];
        A->data[q][j] = s * A->data[p][j] + c * A->data[q][j];
        A->data[p][j] = tmp;
    }
    
    // Apply rotation to columns
    for (int j = 0; j < k; j++) {
        double tmp = c * A->data[j][p] - s * A->data[j][q];
        A->data[j][q] = s * A->data[j][p] + c * A->data[j][q];
        A->data[j][p] = tmp;
    }
}

// Check if deflation is possible
int deflationPossible(Matrix* A, int n, double tol) {
    return fabs(A->data[n-1][n-2]) < tol;
}

// Matrix creation helper
Matrix* createMatrix(int rows, int cols) {
    Matrix* m = (Matrix*)malloc(sizeof(Matrix));
    if (!m) {
        printf("Memory allocation failed for matrix structure\n");
        exit(1);
    }
    
    m->rows = rows;
    m->cols = cols;
    m->data = (double**)malloc(rows * sizeof(double*));
    if (!m->data) {
        printf("Memory allocation failed for matrix rows\n");
        free(m);
        exit(1);
    }
    
    for (int i = 0; i < rows; i++) {
        m->data[i] = (double*)calloc(cols, sizeof(double));
        if (!m->data[i]) {
            printf("Memory allocation failed for matrix column %d\n", i);
            for (int j = 0; j < i; j++) {
                free(m->data[j]);
            }
            free(m->data);
            free(m);
            exit(1);
        }
    }
    return m;
}

// Matrix cleanup helper
void destroyMatrix(Matrix* m) {
    if (m) {
        if (m->data) {
            for (int i = 0; i < m->rows; i++) {
                free(m->data[i]);
            }
            free(m->data);
        }
        free(m);
    }
}

// Matrix copy helper
void copyMatrix(Matrix* dest, Matrix* src) {
    for (int i = 0; i < src->rows; i++) {
        for (int j = 0; j < src->cols; j++) {
            dest->data[i][j] = src->data[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter matrix size: ");
    scanf("%d", &n);
    
    Matrix* A = createMatrix(n, n);
    double* eigenvalues = (double*)malloc(n * sizeof(double));
    if (!eigenvalues) {
        printf("Memory allocation failed for eigenvalues\n");
        destroyMatrix(A);
        exit(1);
    }
    
    printf("Enter matrix values:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A->data[i][j]);
        }
    }
    
    improvedQR(A, eigenvalues, SHIFT_STRATEGY_WILKINSON);
    
    printf("\nEigenvalues:\n");
    for (int i = 0; i < n; i++) {
        printf("%.*g\n", DBL_DIG, eigenvalues[i]);
    }
    
    free(eigenvalues);
    destroyMatrix(A);
    
    return 0;
}
