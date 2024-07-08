import sys
import matplotlib.pyplot as plt
import numpy as np

# Data
categories = ['L1 Cache', 'RAM', 'L2 Cache', 'L3 Cache']
amat_values = [float(item) for item in sys.argv[1:]]

if(len(sys.argv) == 3):
    amat_values.append(0)
    amat_values.append(0)
elif(len(sys.argv) == 4):
    amat_values.append(0)

# Plotting
plt.figure(figsize=(10, 6))
plt.bar(categories, amat_values, color=['blue', 'green', 'orange', 'red'])
plt.xlabel('Memory Hierarchy Level')
plt.ylabel('Average Memory Access Time (AMAT)')
plt.title('Comparison of Average Memory Access Time')
plt.ylim(0, max(amat_values) * 1.2)  # Adjust ylim for better visualization
plt.grid(True, axis='y')  # Show grid lines on y-axis
plt.show()
