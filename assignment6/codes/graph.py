import matplotlib.pyplot as plt

# Define the coordinates of the triangle's vertices
x = [0, 2, 0]
y = [0, 0, 1]

# Create the plot
plt.figure()
plt.fill(x, y, 'gray', edgecolor='black', alpha=0.5)
plt.xlim(0, 2.5)
plt.ylim(0, 1.5)

# Set labels and title
plt.xlabel('x')
plt.ylabel('y')
plt.title('Shaded triangular region P')

# Save the plot as graph.png
plt.grid(True)
plt.savefig('graph.png')

# Optionally, display the plot (remove this if not needed)
plt.show()
