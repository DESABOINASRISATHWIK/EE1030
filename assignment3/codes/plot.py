import numpy as np
import matplotlib.pyplot as plt

# Load the points from the file
data = np.loadtxt("points.dat", delimiter=",", skiprows=1)  # Skip the header line

# Extract x and y coordinates
x = data[:, 0]
y = data[:, 1]

# Plot the curve
plt.figure(figsize=(8, 6))
plt.plot(x, y, label='Points on the Circle', color='blue', marker='o', markersize=3)
plt.title('Points on the Unit Circle Centered at O(0, 0)')
plt.xlabel('x')
plt.ylabel('y')
plt.axhline(0, color='black', linewidth=0.5, ls='--')
plt.axvline(0, color='black', linewidth=0.5, ls='--')
plt.grid()
plt.axis('equal')
plt.legend()

# Label the center O
plt.text(0, 0, 'O(0, 0)', fontsize=12, ha='right', color='red')

# Save the plot as a PNG file
plt.savefig("plot.png", dpi=300)  # Save with 300 dpi for better quality

# Optional: Show the plot (if you still want to see it)
# plt.show()

