import matplotlib.pyplot as plt
import numpy as np

# Define the points
A = (4, 0)
B = (4, 8)
O = (4, 4)

# Calculate the radius
radius = np.linalg.norm(np.array(O) - np.array(A))

# Create a figure and axis
fig, ax = plt.subplots()

# Plot the circle
circle = plt.Circle(O, radius, color='blue', fill=False, linestyle='--', linewidth=2)
ax.add_artist(circle)

# Plot the points A, B, and O
ax.plot(*A, 'ro')  # Point A
ax.plot(*B, 'ro')  # Point B
ax.plot(*O, 'go')  # Center O

# Label the points
ax.text(A[0], A[1], 'A(4,0)', fontsize=12, verticalalignment='bottom', horizontalalignment='right')
ax.text(B[0], B[1], 'B(4,8)', fontsize=12, verticalalignment='top', horizontalalignment='right')
ax.text(O[0], O[1], 'O(4,4)', fontsize=12, verticalalignment='bottom', horizontalalignment='left')

# Set the aspect of the plot to be equal
ax.set_aspect('equal')

# Set the limits of the plot
ax.set_xlim(0, 8)
ax.set_ylim(-2, 10)

# Add grid
ax.grid(True)

# Set labels and title
plt.xlabel('x')
plt.ylabel('y')
plt.title('Circle with Center O(4,4) and Diameter Points A(4,0) and B(4,8)')

# Show the plot
plt.show()
# Save the plot as a PNG file
plt.savefig('circle_plot.png', format='png', bbox_inches='tight')

