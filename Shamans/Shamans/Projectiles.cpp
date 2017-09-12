#include "Projectiles.h"



Projectiles::Projectiles()
{

	//TODO: all of this code is for testing, need to create a texture map to associate textures with key codes.
	
	texture = new sf::Texture;
	texture->loadFromFile("Resources/ice_ball.png");
	sprite.setTexture(*texture);
}


Projectiles::~Projectiles()
{
	delete texture;
}

void Projectiles::activate(Player * player, sf::Vector2f mouse_coords)
{
}

void Projectiles::render(sf::RenderWindow* window)
{
	sprite.setPosition(500, 500);
	window->draw(sprite);
}

void Projectiles::update()
{
	sprite.move(v_x, v_y);
}

void Projectiles::setPosition()
{
}
