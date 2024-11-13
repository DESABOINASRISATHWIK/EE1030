import numpy as np
import matplotlib.pyplot as plt
 
# Load training data
A = np.loadtxt('training_data.txt')

# Prepare the matrix for least squares fitting
X = np.hstack((np.ones((A.shape[0], 1)), A[:, [0]], A[:, [0]]**2))
T = A[:, [0]]
C = A[:, [1]]

# Least squares method
v, av, bv = np.linalg.lstsq(X, C, rcond=None)[0]
n_lsq = np.zeros((3, 1))
n_lsq[0][0] = v.item()    # Using item() to handle scalar extraction
n_lsq[1][0] = av.item()
n_lsq[2][0] = bv.item()

print(n_lsq)

# Plot training data results
plt.plot(T, X @ n_lsq)
plt.plot(T, C, 'k.')
plt.grid()
plt.ylabel('Output Voltage (V)')
plt.xlabel(r'Temperature ($^{\circ}$C)')  # Using raw string to handle escape sequences
plt.tight_layout()
plt.savefig('../aiml./figs/train.png')

# Close current figure(s)
plt.close('all')

# Load validation data
B = np.loadtxt('validation_data.txt')
Xv = np.hstack((np.ones((B.shape[0], 1)), B[:, [0]], B[:, [0]]**2))
Cv = B[:, [1]]
Tv = B[:, [0]]

# Plot validation data results
plt.plot(Tv, Xv @ n_lsq)
plt.plot(Tv, Cv, 'k.')
plt.ylabel('Output Voltage (V)')
plt.xlabel(r'Temperature ($^{\circ}$C)')  # Using raw string
plt.grid()
plt.tight_layout()
plt.savefig('../aiml./figs/valid.png')
