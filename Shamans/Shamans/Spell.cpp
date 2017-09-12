#include "Spell.h"
#include <iostream>

Spell::Spell(Player * player, float w_x, float w_y): p_radius(10)
{

	velocity = new sf::Vector2f(w_x, w_y);
	velocity->x -= player->getPosition().x;
	velocity->y -= player->getPosition().y;
	float length = sqrt((velocity->x * velocity->x) + (velocity->y * velocity->y));
	velocity->x = velocity->x / length;
	velocity->y = velocity->y / length;
	circle = new sf::CircleShape(20);
	circle->setPosition(player->getPosition());
	circle->setFillColor(sf::Color(255, 0, 0));
}

Spell::~Spell()
{
	delete circle;
	delete velocity;
}

void Spell::update()
{
	circle->move(velocity->x, velocity->y);
}

sf::CircleShape* Spell::getCircle()
{
	return circle;
}

int Spell::getPowerRadius()
{
	return p_radius;
}
