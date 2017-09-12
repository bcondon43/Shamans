#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Player.h"
#include "PixelMap.h"
#include "Spell.h"


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
	float x_offset;
	float y_offset;
	Player myPlayer;

	PixelMap* pixelMap;
	std::vector<Player> players;
	std::vector<Spell*> spells;
	bool pressed;
};

#endif