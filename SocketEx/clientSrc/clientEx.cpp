#include <iostream>
#include "socket.hpp"

int main() {
	std::cout << "Hello world" << std::endl;
	//std::cout << "2 + 3 = " << mearlymath::add(2,3) << std::endl;
	
	Socket::Ptr client = std::make_shared<Socket>("127.0.0.1", 12345); 	
	client->socket_connect();

	std::string string_to_server = "1.5025 0.968055 0.232981 -0.0926812 -0.0194594 -0.239543 0.96855 -0.0673029 -.0345974 0.0740861 0.0873541 0.993419 1.12059 0.0 0.0 0.0 1.0";
	
	std::cout << "Waiting for message..." << std::endl;
	std::string output = client->socket_receive();
	std::cout << "Server>" << output << std::endl;
	client->socket_send(string_to_server);
	
	
	return 0;
}

