#include "Scene.h"
#include <iostream>
#define MOVE_OFFSET 3.f

Scene::Scene(sf::RenderWindow* window) : pressed(false)
{
	Scene::window = window;
	pixelMap = new PixelMap();
	pixelMap->load("Resources/grass_map.png");

	Player myPlayer;
	myPlayer.setPosition(10, 10);
}


Scene::~Scene()
{
	delete pixelMap;
	for (std::vector<Spell*>::iterator it = spells.begin(); it != spells.end(); ++it) {
		delete *it;
	}
}


void Scene::render(){
	//Renders the scene
	sf::View map_view(sf::FloatRect(0, 0, (float)window->getSize().x,(float)window->getSize().y));
	map_view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	map_view.move(x_offset,y_offset);
	window->setView(map_view);


	//Renders destructible map
	sf::Texture texture;
		texture.create(pixelMap->getWidth(), pixelMap->getHeight());
		texture.update(pixelMap->getPixels());
	sf::Sprite sprite(texture);
	window->draw(sprite);


	window->draw((sf::RectangleShape) (myPlayer));

	for (std::vector<Spell*>::iterator it = spells.begin(); it != spells.end(); ++it) {
		window->draw(*((*it)->getCircle()));
	}
	
}

void Scene::input(){
	//Moves the grid
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		x_offset += MOVE_OFFSET;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		x_offset -= MOVE_OFFSET;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		y_offset += MOVE_OFFSET;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		y_offset -= MOVE_OFFSET;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !pressed) {
		pressed = true;
	}
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && pressed) {
		//pixelMap->destroyCircle(sf::Mouse::getPosition(*window).x +x_offset, sf::Mouse::getPosition(*window).y+y_offset, 100);
		spells.push_back(new Spell(&myPlayer, sf::Mouse::getPosition(*window).x + x_offset, sf::Mouse::getPosition(*window).y + y_offset));
		pressed = false;
	}
}
void Scene::update(float delta){
	//updates players
	myPlayer.update(delta);


	//Updates spells
	for (std::vector<Spell*>::iterator it = spells.begin(); it != spells.end();) {
		(*it)->update(delta);
		if (pixelMap->checkHitCircle((*it)->getCircle())) {
			delete *it;
			it = spells.erase(it);
			std::cout << "ERASED A SPELL" << std::endl;
		}
		else
			++it;
	}
}