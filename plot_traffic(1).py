import matplotlib.pyplot as plt

# Data from Tshark
timestamps = [0.000627, 0.003314, 0.809639, 0.813676, 1.589034, 1.590462]
lengths = [224, 5212, 200, 13972, 200, 6672]

# Plot
plt.plot(timestamps, lengths, marker='o', linestyle='-', color='b', label='Packet Length')
plt.xlabel('Time (seconds)')
plt.ylabel('Packet Length (bytes)')
plt.title('HTTP Traffic for dh_challenge.exe Download')
plt.legend()
plt.grid(True)
plt.show()