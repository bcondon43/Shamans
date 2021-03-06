#include "Spell.h"
#include <iostream>
#define SLOW_DOWN 2.0f

Spell::Spell(Player * player, float w_x, float w_y): p_radius(10)
{

	velocity = new sf::Vector2f(w_x, w_y);
	velocity->x -= player->getPosition().x;
	velocity->y -= player->getPosition().y;
	float length = sqrt((velocity->x * velocity->x) + (velocity->y * velocity->y));
	velocity->x = velocity->x / (SLOW_DOWN * length);
	velocity->y = velocity->y / (SLOW_DOWN * length);
	circle = new sf::CircleShape(20);
	circle->setPosition(player->getPosition());
	circle->move(-circle->getRadius(), -circle->getRadius());
	circle->setFillColor(sf::Color(255, 0, 0));
}

Spell::~Spell()
{
	delete circle;
	delete velocity;
}

void Spell::update(float delta)
{
	circle->move(velocity->x * delta, velocity->y * delta);
}

sf::CircleShape* Spell::getCircle()
{
	return circle;
}

int Spell::getPowerRadius()
{
	return p_radius;
}
