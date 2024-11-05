#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void write_points(FILE *fptr, double center[2], double pointA[2], double pointB[2], int num_points) {
    double radius = sqrt(pow(pointA[0] - center[0], 2) + pow(pointA[1] - center[1], 2));
    
    for (int i = 0; i < num_points; i++) {
        double angle = (i * 2 * M_PI) / num_points; // Calculate angle for each point
        double x = center[0] + radius * cos(angle); // x-coordinate
        double y = center[1] + radius * sin(angle); // y-coordinate
        fprintf(fptr, "%lf,%lf\n", x, y); // Write point to file
    }
}

int main() {
    // Define points O, A, B
    double O[2] = {4.0, 4.0}; // Center
    double A[2] = {4.0, 0.0}; // Point A
    double B[2] = {4.0, 8.0}; // Point B

    // Open file to write points
    FILE *fptr = fopen("points.dat", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write center and points A, B to the file
    fprintf(fptr, "O: (%lf, %lf)\n", O[0], O[1]);
    fprintf(fptr, "A: (%lf, %lf)\n", A[0], A[1]);
    fprintf(fptr, "B: (%lf, %lf)\n", B[0], B[1]);
    
    // Generate and write points along the circle
    int num_points = 100; // Number of points on the circle
    write_points(fptr, O, A, B, num_points);

    // Close the file
    fclose(fptr);
    printf("Points written to points.dat successfully.\n");

    return 0;
}

