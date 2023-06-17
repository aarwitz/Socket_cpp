#include <iostream>
#include "socket.hpp"

int main() {
	// Connect to localhost socket
	Socket::Ptr client = std::make_shared<Socket>("127.0.0.1", 12345); 	
	client->socket_connect();
	// Receive a message from server
	std::string output = client->socket_receive();
	std::cout << "Server>" << output << std::endl;
	// Type message to send back to server
	std::string msg;
	std::cout << "Type message to send to server: ";
	std::cin >> msg;
	// Send message
	client->socket_send(msg);
	return 0;
}

