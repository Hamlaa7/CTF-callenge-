# CTF-callenge:
# 🧠 Challenge Idea:
The main goal of this challenge is: the developer creates a key using weak parameters, and the participant must write code to break it and recover the secret.

## 🛠️ Tools Used:
- **GCC**: For compiling the C challenge and solution code
- **VS Code**: Code editing and development
- **Msys**:It provides a Unix-like environment for windows
- **Python**: Used with `Sympy` and `pwntools` for brute-force key recovery
- **Nmap**: Service discovery and DHKE vulnerability mapping
- **Tshark**: Network analysis and key extraction from `.pcap` files
- **tcpdump**: Used to capture traffic for the challenge
- **Docker**: To host the challenge in a reproducible environment
- **CTFd**: For deployment on a CTF platform

## 🧪 How to Run:
1. Launch the server using the provided Dockerfile.
2. Open the provided `.pcap` files using Wireshark or Tshark.
3. Extract the public keys and analyze the DHKE exchange.
4. Reverse engineer the binary using Radare2 or IDA.
5. Use Python scripts to brute-force the shared key and retrieve the flag.

## 📂 Files:
- `dh_challenge.c / .exe`: vulnerable binary implementation
- `dh_solution.c / .exe`: expected solution binary
- `.pcap`: captured network traffic with DH exchange
- `plot_traffic(1).py`: helper script for traffic visualization
- `Dockerfile`: challenge deployment environment
