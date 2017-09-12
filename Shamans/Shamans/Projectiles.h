#ifndef PROJECTILES_H
#define PROJECTILES_H

#include "Player.h"
class Projectiles
{
public:
	Projectiles();
	~Projectiles();


	void activate(Player* player, sf::Vector2f mouse_coords);
	void render(sf::RenderWindow* window);
	void update();
	void setPosition();

private:
	int p_radius;
	sf::Sprite sprite;
	sf::Texture* texture;
	int v_x;
	int v_y;
};

#endif