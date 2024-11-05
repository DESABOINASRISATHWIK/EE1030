#include <stdio.h>

void calculate_midpoint(float ax, float ay, float bx, float by) {
    float midX = (ax + bx) / 2.0;
    float midY = (ay + by) / 2.0;

    // Open the file to write the result
    FILE *file = fopen("result.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Write the result to the file
    fprintf(file, "The midpoint O of A(%.1f, %.1f) and B(%.1f, %.1f) is O(%.1f, %.1f).\n", 
            ax, ay, bx, by, midX, midY);
    
    // Close the file
    fclose(file);
}

