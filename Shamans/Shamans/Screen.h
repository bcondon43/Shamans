#ifndef SCREEN_H
#define SCREEN_H
#include <SFML/Graphics.hpp>

class Screen
{
public:
	Screen(unsigned int width, unsigned int height, char* title);
	~Screen();

	void render();
	void input();
	void update();
	bool isOpen();
private:
	sf::RenderWindow window;
	unsigned int width;
	unsigned int height;
};

#endif