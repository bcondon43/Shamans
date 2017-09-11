#include "Scene.h"

#define MOVE_OFFSET 2.f

Scene::Scene(sf::RenderWindow* window)
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
}


void Scene::render(){
	//Renders the scene
	sf::View map_view(sf::FloatRect(0, 0, (float)window->getSize().x,(float)window->getSize().y));
	map_view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	map_view.move(x_offset,y_offset);
	window->setView(map_view);

	pixelMap->destroyCircle(900, 700, 100);
	
	sf::Texture texture;
	texture.create(pixelMap->getWidth(), pixelMap->getHeight());
	texture.update(pixelMap->getPixels());
	sf::Sprite sprite(texture);


	
	window->draw(sprite);
	window->draw((sf::RectangleShape) (myPlayer));
	
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