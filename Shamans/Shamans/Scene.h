#ifndef SCENE_H
#define SCENE_H
#include "PixelMap.h"
#include "Player.h"
class Scene
{
public:
	Scene(sf::RenderWindow* window);
	~Scene();

	void render();
	void input();
	void update();
private:
	sf::RenderWindow* window;
	PixelMap* pixelMap;
	float x_offset;
	float y_offset;
	Player myPlayer;
};

#endif