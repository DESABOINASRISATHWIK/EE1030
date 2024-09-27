#include <stdio.h>
#include <math.h>

void plot_points() {
    // Define points O, A, and B
    double x[] = {4.0, 4.0, 4.0}; // X-coordinates for O, A, B
    double y[] = {4.0, 0.0, 8.0}; // Y-coordinates for O, A, B
    int count = 3; // Number of points

    // Open a pipe to Gnuplot
    FILE *gp;
    gp = popen("gnuplot -persistent", "w");
    if (gp == NULL) {
        printf("Error opening gnuplot.\n");
        return;
    }

    // Set up the plot
    fprintf(gp, "set title 'Plot of Points O, A, B and Circle'\n");
    fprintf(gp, "set xlabel 'X-axis'\n");
    fprintf(gp, "set ylabel 'Y-axis'\n");
    fprintf(gp, "set xrange [0:8]\n"); // Set x range for 8x8 grid
    fprintf(gp, "set yrange [0:8]\n"); // Set y range for 8x8 grid
    fprintf(gp, "set size ratio 1\n"); // Equal scaling for x and y
    fprintf(gp, "set grid\n"); // Add grid lines

    // Set output to a PNG file
    fprintf(gp, "set terminal pngcairo\n");
    fprintf(gp, "set output 'plot.png'\n");

    // Draw the circle with center O(4,4) and radius 4
    fprintf(gp, "set parametric\n");
    fprintf(gp, "plot 4 + 4*cos(t), 4 + 4*sin(t) title 'Circle (O, r=4)', '-' with points pointtype 7 title 'Points'\n");

    // Plotting the points O, A, B
    for (int i = 0; i < count; i++) {
        fprintf(gp, "%lf %lf\n", x[i], y[i]);
    }
    fprintf(gp, "e\n");

    // Label the points
    fprintf(gp, "set label 'O(4,4)' at 4, 4 offset 0.5, 0.5\n");
    fprintf(gp, "set label 'A(4,0)' at 4, 0 offset 0.5, -0.5\n");
    fprintf(gp, "set label 'B(4,8)' at 4, 8 offset 0.5, 0.5\n");

    // Replot to include labels
    fprintf(gp, "replot\n");
    
    // Close the output
    fprintf(gp, "unset output\n");
    
    // Close Gnuplot
    pclose(gp);
}

