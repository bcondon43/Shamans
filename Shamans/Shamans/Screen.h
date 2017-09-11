#ifndef SCREEN_H
#define SCREEN_H
#include "Scene.h"

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
	Scene* scene;
	char* title;
	unsigned int width;
	unsigned int height;
};

#endif