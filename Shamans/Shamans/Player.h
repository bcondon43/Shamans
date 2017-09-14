#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>

class Player : public sf::RectangleShape
{
public:
	Player();
	~Player();
	
	void update(float delta);
};

#endif