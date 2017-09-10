#ifndef NETWORK_H
#define NETWORK_H
#include <SFML\Network.hpp>


/**
This class has yet to be tested
*/
class Network
{
public:
	Network();
	~Network();

	bool connect(char* IP = "127.0.0.1", int PORT = 20000);
	void send(char* message);
	char* receive();
private:
	sf::TcpSocket socket;
};

#endif
