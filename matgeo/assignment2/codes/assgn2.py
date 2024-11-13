import numpy as np
import matplotlib.pyplot as plt

# Read the points from the .dat file
def read_points(filename):
    try:
        # Load data, skipping header lines that start with 'O:', 'A:', or 'B:'
        points = np.loadtxt(filename, delimiter=',', skiprows=3)  # Adjust skiprows based on the number of header lines
        return points
    except FileNotFoundError:
        print(f"Error: The file {filename} was not found.")
        return []
    except ValueError:
        print("Error: Invalid format in the file.")
        return []

# Main function to plot the circle and points
def plot_circle_with_points(filename):
    # Read points from the file
    points = read_points(filename)

    if points.size == 0:
        print("No points to plot.")
        return

    # Extract circle points
    circle_x = points[:, 0]
    circle_y = points[:, 1]

    # Create a smaller figure (adjusted dimensions)
    plt.figure(figsize=(3,3))  # Adjusted figure size (width, height)

    # Plot the circle points
    plt.plot(circle_x, circle_y, label='Circle Points', color='blue')

    # Mark points O, A, and B
    plt.plot(4, 4, 'ro', label='Point O (4, 4)')  # Center O
    plt.plot(4, 0, 'go', label='Point A (4, 0)')  # Point A
    plt.plot(4, 8, 'bo', label='Point B (4, 8)')  # Point B

    # Add labels and legend
    plt.title('Circle with Center O and Points A, B')
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.axhline(0, color='black', linewidth=0.5, ls='--')
    plt.axvline(0, color='black', linewidth=0.5, ls='--')
    plt.grid(color='gray', linestyle='--', linewidth=0.5)
    plt.axis('equal')  # Equal scaling
    plt.legend()

    # Save the plot as a PNG file with reduced dimensions
    plt.savefig('circle_plot.png', format='png', bbox_inches='tight')  # Adjust as needed for minimal whitespace

    # Show the plot
    plt.show()

# Call the function with the path to your .dat file
plot_circle_with_points('points.dat')


