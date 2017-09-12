#include "Player.h"


Player::Player()
{
	setTexture(new sf::Texture());
	setFillColor(sf::Color::Blue);
	setSize(sf::Vector2f(64, 128));
}


Player::~Player()
{
}