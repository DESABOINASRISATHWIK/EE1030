import matplotlib.pyplot as plt
import numpy as np
import os

# Create folder if it doesn't exist
os.makedirs('figs', exist_ok=True)

# Define the sieve sizes (x-axis) and percentage passing (y-axis) for three curves
sieve_size = np.linspace(0, 100, 100)
P = 1 / (1 + np.exp(-0.1 * (sieve_size - 50))) * 100  # Curve P
Q = 1 / (1 + np.exp(-0.1 * (sieve_size - 55))) * 100  # Curve Q
R = 1 / (1 + np.exp(-0.1 * (sieve_size - 60))) * 100  # Curve R

# Plotting the graph
plt.figure(figsize=(8, 6))
plt.plot(sieve_size, P, 'k--', label='P')   # dashed line for P
plt.plot(sieve_size, Q, 'k-', label='Q')    # solid line for Q
plt.plot(sieve_size, R, 'k-.', label='R')   # dash-dot line for R

# Labels and title
plt.xlabel('Sieve size')
plt.ylabel('Percentage passing')
plt.legend(loc='lower right')

# Saving the plot as 'graph.png' in the 'figs' directory
plt.savefig('figs/graph.png')

plt.show()

