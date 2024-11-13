import ctypes

# Load the shared library
midpoint_lib = ctypes.CDLL('./midpoint.so')

# Define the function prototype
midpoint_lib.calculate_midpoint.argtypes = [ctypes.c_float, ctypes.c_float, 
                                             ctypes.c_float, ctypes.c_float]

# Coordinates of points A and B
A = (4, 0)  # A(4, 0)
B = (4, 8)  # B(4, 8)

# Call the C function
midpoint_lib.calculate_midpoint(A[0], A[1], B[0], B[1])

# Read the result from the file
with open("result.txt", "r") as file:
    result = file.read()

# Output the result
print(result)

