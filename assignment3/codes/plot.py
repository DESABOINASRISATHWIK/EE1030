import numpy as np
import matplotlib.pyplot as plt

# Load the points from the file
data = np.loadtxt("points.dat", delimiter=",", skiprows=1)  # Skip the header line

# Extract the center point O from the data file
center_x = data[0, 0]  # Should be 0
center_y = data[0, 1]  # Should be 0

# Set the value of a
a = 1  # You can change this to any real number you like

# Generate t values from -1 to 1
t = np.linspace(-1, 1, 100)  # 100 points between -1 and 1

# Calculate x and y coordinates based on the equations
x = (2 * a * t) / (1 + t**2)
y = (a * (1 - t**2)) / (1 + t**2)

# Create a plot
plt.figure(figsize=(8, 6))
plt.plot(x, y, label='Points on the Circle', color='blue', marker='o', markersize=3)

# Set the plot title and labels
plt.title('Points on the Circle Centered at O(0, 0)')
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

