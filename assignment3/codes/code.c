#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void write_circle_points(FILE *fptr, double center[2], int num_points) {
    double radius = 1.0; // Set radius for the unit circle

    for (int i = 0; i < num_points; i++) {
        double angle = (i * 2 * M_PI) / num_points; // Calculate angle for each point
        double x = center[0] + radius * cos(angle); // x-coordinate
        double y = center[1] + radius * sin(angle); // y-coordinate
        fprintf(fptr, "%lf,%lf\n", x, y); // Write point to file
    }
}

void write_transformed_points(FILE *fptr, int num_points, double a) {
    for (int i = 0; i < num_points; i++) {
        double t = -1 + 2.0 * i / (num_points - 1); // Generate t from -1 to 1
        double x = (2 * a * t) / (1 + t * t); // x-coordinate
        double y = (a * (1 - t * t)) / (1 + t * t); // y-coordinate
        fprintf(fptr, "%lf,%lf\n", x, y); // Write transformed point to file
    }
}

int main() {
    // Define the center O
    double O[2] = {0.0, 0.0}; // Center at (0, 0)

    // Open file to write points
    FILE *fptr = fopen("points.dat", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write the center to the file
    fprintf(fptr, "O: (%lf, %lf)\n", O[0], O[1]);
    
    // Generate and write points along the circle
    int num_circle_points = 100; // Number of points on the circle
    write_circle_points(fptr, O, num_circle_points);
    
    // Generate and write transformed points
    int num_transformed_points = 100; // Number of transformed points
    double a = 1.0; // Set the value of a
    write_transformed_points(fptr, num_transformed_points, a);

    // Close the file
    fclose(fptr);
    printf("Points written to points.dat successfully.\n");

    return 0;
}

