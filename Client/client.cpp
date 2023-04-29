
#include "../socket.hpp"

/*
Compile with:
g++ client.cpp -o client
*/

static bool isConnected = true;
using namespace std::chrono_literals;

void Socket::socket_connect()
{
	std::cout << "Creating socket... " << std::endl;
	// Initialize member variable m_sock
	m_sock = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(m_port);
	inet_pton(AF_INET, m_ipAddress.c_str(), &hint.sin_addr);
	
	//	Connect to the server on the socket
	int connectRes = connect(m_sock, (sockaddr*)&hint, sizeof(hint));
	if (connectRes == -1)
	{
	   std::cout << "not connecting" << "\n";
	}
	else
	{
	   std::cout << "Connected" << std::endl;
	}
}

std::string Socket::socket_receive() 
{
	//char buf[4096];
	char *buf = (char *) malloc(200000788);
	
	//Wait for response
	//memset(buf, 0, 4096);
	int bytesReceived = recv(m_sock, buf, 200000788, 0);
	std::cout << "bytesReceived" << (int)bytesReceived << std::endl;
	if (bytesReceived == -1)
	{
	 std::cout << "There was an error getting response from server\r\n";
	}
	if (bytesReceived == 0) {
		std::cout << "Client disconnected" << std::endl;
	}
	else
	{
	 //		Display response
	 std::cout << "Received\n";
	}
	
	return std::string(buf,bytesReceived);
}

void Socket::socket_send(std::string& pc_text)
{
	// Send point cloud to Windows PC for Patmax localization
	int sendRes = send(m_sock, pc_text.c_str(), pc_text.size() + 1, 0);
	if (sendRes == -1)
	{
	 std::cout << "Could not send to server! Whoops!\r\n";
	}
	else
	{
	 std::cout << "Patmax output sent to Windows PC" << std::endl;
	}
}

void Socket::socket_close()
{
	close(m_sock);
}


// server connects to client
// loop at random time (always in this order though)
	// at some random time server sends client point cloud
	// at some random time later, client sends back a pick point




