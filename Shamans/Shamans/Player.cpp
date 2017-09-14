#include "Player.h"
#define GRAVITY 1.f

Player::Player()
{
	setTexture(new sf::Texture());
	setFillColor(sf::Color::Blue);
	setSize(sf::Vector2f(64, 128));
}


Player::~Player()
{
}

void Player::update(float delta)
{
	//move(0, GRAVITY * delta);
}
