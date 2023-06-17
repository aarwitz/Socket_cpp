#ifndef WINDOWS_SOCKET_HPP_80D4D664_F198_11E8_95DB_B06EBF8452C2
#define WINDOWS_SOCKET_HPP_80D4D664_F198_11E8_95DB_B06EBF8452C2

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <thread>
#include <iostream>
#include <memory>


class Socket
{

	public:
		typedef std::shared_ptr<Socket> Ptr;
	
	public:
		//using Ptr = std::shared_ptr<WindowsSocket>;
		
		Socket(std::string ipAddress, int port) : 
			m_ipAddress(ipAddress), m_port(port), m_sock(0) {}
		
		void socket_connect();		
				 
		std::string socket_receive();
		
		void socket_send(std::string& pc_text);
		
		void socket_close();

	private:
		std::string m_ipAddress;
		int m_port;
		int m_sock;

};

#endif // WINDOWS_SOCKET_HPP_80D4D664_F198_11E8_95DB_B06EBF8452C2
