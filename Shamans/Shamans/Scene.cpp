#include "Scene.h"

#define MOVE_OFFSET 2.f

Scene::Scene(sf::RenderWindow* window)
{
	Scene::window = window;
	pixelMap = new PixelMap();
	pixelMap->load("Resources/grass_map.png");
}


Scene::~Scene()
{
	delete pixelMap;
}


void Scene::render(){
	//Renders the scene
	sf::View map_view(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
	map_view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	map_view.move(x_offset,y_offset);
	window->setView(map_view);
	
	sf::Texture texture;
	texture.create(pixelMap->getWidth(), pixelMap->getHeight());
	texture.update(pixelMap->getPixels());
	sf::Sprite sprite(texture);


	
	window->draw(sprite);
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
}
void Scene::update(){}