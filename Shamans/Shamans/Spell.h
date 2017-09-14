#ifndef SPELL_H
#define SPELL_H
#include "Player.h"

class Spell
{
public:
	Spell(Player* player, float w_x, float w_y);
	~Spell();

	void update(float delta);
	sf::CircleShape* getCircle();
	int getPowerRadius();
private:
	sf::CircleShape* circle;
	sf::Vector2f* velocity;
	int p_radius;
};

#endif