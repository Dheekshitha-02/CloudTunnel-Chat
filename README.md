# CloudTunnel-Chat
CloudTunnel Chat is a basic socket-based messaging system developed in C that demonstrates how devices across different networks can securely communicate using SSH tunneling and cloud hosting (via Google Cloud Platform). It enables real-time bidirectional communication between a client and server using the TCP protocol.

## 🌐 Core Concept
The project explores two methods of enabling communication between devices on different networks:

#### 1. SSH Tunneling
Creates a secure tunnel between local and remote machines using SSH and tools like Ngrok.

#### 2. Google Cloud Hosting (GCP)
Hosts the server on a public virtual machine (VM) via GCP's Compute Engine, allowing global access using a public IP.

## ⚙️ How It Works
- The server listens on a specified port and waits for client connection requests.
- The client connects to the server's public IP (or tunneled endpoint).
- Both parties can exchange messages over a TCP socket.
- Communication continues until either side types end.
  
## 🛠️ Technologies Used
- Language: C
- Protocol: TCP/IP
- Networking: Socket programming
- Hosting: Google Cloud VM, SSH tunneling with Ngrok

## 📁 File Structure
bash
```
CloudTunnelChat/
├── client.c         # Client-side C program
├── server.c         # Server-side C program
├── README.md        # Project overview and usage
├── /screenshots/    # Screenshots of output and setup
```
## 🚀 How to Compile & Run
### Step 1: Compile Both Programs
bash
```
gcc server.c -o server
gcc client.c -o client
```
### Step 2: On the Server (GCP VM or host machine)
bash
```
./server
```
### Step 3: On the Client (local or remote machine)
bash
```
./client
```
## 🔐 SSH Tunneling Example
bash
```
# From client machine to GCP or public server:
ssh -L 9009:localhost:9009 username@<GCP_Public_IP>
```
You can now run the client program locally and connect to the tunneled server port 9009.

## 📌 Notes
- Make sure the firewall allows port 9009 on your VM or local server.
- Use Ctrl+C to terminate the program manually if needed.
- Type end to gracefully close the chat from either side.
