import numpy as np
import matplotlib.pyplot as plt

# Load the points from the file (now space-separated)
data = np.loadtxt("points.dat", delimiter=" ")

# Extract the center point O from the data file (first point)
center_x = data[0, 0]  # Should be 0.0
center_y = data[0, 1]  # Should be 0.0

# Separate the circle points and transformed points
circle_points = data[1:101]  # Assuming first 100 points are from the circle
transformed_points = data[101:]  # Remaining points are transformed points

# Create a plot with minimized dimensions
plt.figure(figsize=(5, 4))  # Changed dimensions to 5x4 inches

# Plot the circle points
plt.plot(circle_points[:, 0], circle_points[:, 1], label='Circle Points', color='blue', linestyle='-', marker='o', markersize=4)

# Plot the transformed points (without a label)
plt.plot(transformed_points[:, 0], transformed_points[:, 1], color='red', linestyle='-', marker='o', markersize=4)

# Set the plot title and labels
plt.title('Circle Points')  # Removed transformed points from the title
plt.xlabel('x')
plt.ylabel('y')
plt.axhline(0, color='black', linewidth=0.5, ls='--')
plt.axvline(0, color='black', linewidth=0.5, ls='--')
plt.grid()
plt.axis('equal')
plt.legend()

# Save the plot as a PNG file
plt.savefig("plot.png", dpi=300)  # Save with 300 dpi for better quality

# Optional: Show the plot
plt.show()

