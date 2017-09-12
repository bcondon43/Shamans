#include "Screen.h"
#include <iostream>


Screen::Screen(unsigned int width, unsigned int height, char* title)
{
	window.create(sf::VideoMode(width, height), title);
	Screen::width = width;
	Screen::height = height;
	Screen::title = title;
	isFullscreen = false;
	scene = new Scene(&window);
}


Screen::~Screen()
{
	delete scene;
}


void Screen::render() {
	window.clear();

	scene->render();

	window.display();
}

void Screen::input() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
			window.close();
		// Handles resizing the screen
		if (event.type == sf::Event::Resized) {
			width = window.getSize().x;
			height = window.getSize().y;
			window.setView(sf::View(sf::FloatRect(0.f, 0.f, window.getSize().x, window.getSize().y)));
			std::cout << "Resizing" << std::endl;
		}
		//Sets screen to fullscreen when f11 is pressed
		if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F11) && isFullscreen == false) {
			window.create(sf::VideoMode().getDesktopMode(), title, sf::Style::Fullscreen);
			isFullscreen = true;
			std::cout << "Entering Fullscreen" << std::endl;
		}
		//leaves fullscreen mode on f11 or escape
		else if (event.type == sf::Event::KeyPressed && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F11)) && isFullscreen) {
			window.create(sf::VideoMode(width, height), title);
			isFullscreen = false;
			std::cout << "Leaving Fullscreen" << std::endl;
		}
	}


	scene->input();
}

void Screen::update() {
	scene->update();
}

bool Screen::isOpen() {
	return window.isOpen();
}
