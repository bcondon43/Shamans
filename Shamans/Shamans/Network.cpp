#include "Network.h"
#include <iostream>



Network::Network()
{
}


Network::~Network()
{
}


bool Network::connect(char* IP, int PORT){
	
	sf::Socket::Status status = socket.connect(IP, PORT);
	if (status != sf::Socket::Done) {
		std::cout << "Failed to connect!" << std::endl;
		return false;
	}
	else {
		return true;
	}
}

void Network::send(char* message){
	if (socket.send(message, 100) != sf::Socket::Done) {
		std::cout << "Failed to send " << message << std::endl;
	}
}

char* Network::receive(){
	char message[100];
	std::size_t received;
	if (socket.receive(message,100,received) != sf::Socket::Done) {
		std::cout << "Failed to receive" << std::endl;
	}
	return message;
}
