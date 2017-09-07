#ifndef SCREEN_H
#define SCREEN_H
#include "PixelMap.h"

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
	bool isFullscreen;
	char* title;
	PixelMap* pixelMap;
	unsigned int width;
	unsigned int height;
};

#endif