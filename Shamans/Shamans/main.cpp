#include <SFML\Graphics.hpp>

#define WIDTH 800
#define HEIGHT 600
#define TITLE "Shamans"

int main() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

	}
}