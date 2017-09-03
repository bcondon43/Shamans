#include "Screen.h"



Screen::Screen(unsigned int width, unsigned int height, char* title)
{
	window.create(sf::VideoMode(width, height), title);
}


Screen::~Screen()
{
}


void Screen::render() {
	
}

void Screen::input() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Screen::update() {

}

bool Screen::isOpen() {
	return window.isOpen();
}