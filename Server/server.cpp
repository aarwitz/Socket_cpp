
#include "../socket.hpp"



/*
Compile with:
g++ server.cpp -o server -std=c++17 -pthread
*/



using namespace std::chrono_literals;

//static bool myBool = true;

void Socket::socket_connect() {
    // Create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1) {std::cout << "Can't create socket\n";}
 
    // Bind the ip address and port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(m_port);
    inet_pton(AF_INET,  m_ipAddress.c_str(), &hint.sin_addr);
    bind(listening, (sockaddr*)&hint, sizeof(hint));
 
    // Start listening and wait for connection
    listen(listening, SOMAXCONN);
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
 
    m_sock = accept(listening, (sockaddr*)&client, &clientSize);
 
    char host[NI_MAXHOST];      // Client's remote name
    char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on
 
    memset(host, 0, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);
 
    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        std::cout << host << " connected on port " << service << std::endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        std::cout << host << " connected on port " << ntohs(client.sin_port) << std::endl;
    }

	std::cout << "Connected" << std::endl;

    // Close listening socket
    close(listening);
}


std::string Socket::socket_receive() {
	char buf[4096];
	
	//Wait for response
	memset(buf, 0, 4096);

	// waiting
	std::cout << "Waiting for msg..." << std::endl;
	int bytesReceived = recv(m_sock, buf, 4096, 0);
	if (bytesReceived == -1) {
	 std::cout << "There was an error getting response from server\r\n";
	}
	else {
	// Display response
	 std::cout << "Message received.\n";
	}
	
	return std::string(buf,bytesReceived);
}

void Socket::socket_send(std::string& pc_text) {
	std::cout << "Sending: " << pc_text << std::endl;
	int sendRes = send(m_sock, pc_text.c_str(), pc_text.size() + 1, 0);
	if (sendRes == -1) {
	 std::cout << "Could not send to client! Whoops!\r\n";
	}
	else {
	 std::cout << "Point cloud sent to Windows PC" << std::endl;
		//pointCloudSent=true;
	}
}

void Socket::socket_close () {
	close(m_sock);
}

