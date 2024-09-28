import matplotlib.pyplot as plt

# Read the points from the .dat file
def read_points(filename):
    points = []
    with open(filename, 'r') as file:
        for line in file:
            if line.startswith('O:') or line.startswith('A:') or line.startswith('B:'):
                continue  # Skip header lines
            x, y = map(float, line.strip().split(','))
            points.append((x, y))
    return points

# Main function to plot the circle and points
def plot_circle_with_points(filename):
    # Read points from the file
    points = read_points(filename)

    # Extract circle points
    circle_x = [point[0] for point in points]
    circle_y = [point[1] for point in points]

    # Create a smaller figure
    plt.figure(figsize=(6, 6))  # Adjusted figure size (width, height)

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

    # Save the plot as a PNG file
    plt.savefig('circle_plot.png', format='png', bbox_inches='tight')  # Use bbox_inches to minimize whitespace

    # Show the plot
    plt.show()

# Call the function with the path to your .dat file
plot_circle_with_points('points.dat')

