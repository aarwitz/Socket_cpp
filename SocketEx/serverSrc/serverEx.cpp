#include <iostream>
#include "socket.hpp"

int main() {
	// Connect to localhost socket
	Socket::Ptr server = std::make_shared<Socket>("127.0.0.1",12345);
	server->socket_connect();
	// Type message to send to client
	std::string msg;
	std::cout << "Type message to send to client: ";
	std::cin>>msg;
	// Send message
	server->socket_send(msg);
	// Receive a message from client
	std::string output = server->socket_receive();
	std::cout<< "Client>" << output << std::endl;
}
