#include <stdio.h>

int main() {
    // Declare a pointer to the file
    FILE *file;

    // Open the file points.dat for writing (will create it if it doesn't exist)
    file = fopen("points.dat", "w");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;  // Return 1 if there was an error
    }

    // Write the origin point O to the file (x=0, y=0)
    fprintf(file, "0.00000 0.00000\n");

    // Define the number of points and the range of the parameter t
    int num_points = 100;  // Number of points to generate
    double t_start = -1.0, t_end = 1.0;  // Range of t (from -1 to 1)
    double t_increment = (t_end - t_start) / (num_points - 1);  // Step size for t

    // Loop to calculate points and write them to the file
    for (int i = 0; i < num_points; i++) {
        // Calculate t value for the current point
        double t = t_start + i * t_increment;

        // Parametric equations to calculate x and y
        double x = (2 * t) / (1 + t * t);  // Equation for x
        double y = (1 - t * t) / (1 + t * t);  // Equation for y

        // Write the calculated point (x, y) to the file with 5 decimal precision
        fprintf(file, "%.5f %.5f\n", x, y);
    }

    // Close the file
    fclose(file);

    // Print success message
    printf("Data written to points.dat successfully.\n");

    return 0;
}


