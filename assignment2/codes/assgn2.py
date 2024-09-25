import ctypes

# Load the shared library
lib = ctypes.CDLL('./plot_points.so')

# Define the function prototype
lib.plot_points.restype = None

def plot_points():
    lib.plot_points()

# Call the C function to plot the points and circle
plot_points()

