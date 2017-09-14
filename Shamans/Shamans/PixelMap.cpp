#include "PixelMap.h"
#include "SFML\Graphics.hpp"
#include <iostream>


PixelMap::PixelMap()
{
}


PixelMap::~PixelMap()
{
	delete pixels;
	delete pixel_flags;
}


bool PixelMap::load(std::string png_path) {
	sf::Image map;

	if (!map.loadFromFile(png_path)) {
		std::cout << "Failed to load png" << std::endl;
		return false;
	}
	width = map.getSize().x;
	height = map.getSize().y;
	pixels = new sf::Uint8[map.getSize().x * map.getSize().y * 4];
	pixel_flags = new char[map.getSize().x * map.getSize().y];
	
	const sf::Uint8* temp_pixels = map.getPixelsPtr();
	
	for (unsigned int i = 0; i < map.getSize().x * map.getSize().y * 4; i += 4) {
		pixels[i] = temp_pixels[i];
		pixels[i + 1] = temp_pixels[i + 1];
		pixels[i + 2] = temp_pixels[i + 2];
		pixels[i + 3] = temp_pixels[i + 3];
		if (pixels[i + 3] != 0) {
			pixel_flags[i / 4] = 1;
		}
		else {
			pixel_flags[i / 4] = 0;
		}
	}
	std::cout << "Finished loading png" << std::endl;
	return true;
}

sf::Uint8* PixelMap::getPixels() {
	return pixels;
}

int PixelMap::getWidth() {
	return width;
}
int PixelMap::getHeight() {
	return height;
}

void PixelMap::destroyCircle(int w_x, int w_y, int radius) {
	for (int y = -radius; y <= radius; y++){
		for (int x = -radius; x <= radius; x++) {
			if (x*x + y*y <= radius*radius) {
				int x_t = w_x + x;
				int y_t = w_y + y;
				if ((y_t * width) + x_t < width * height && (y_t * width) + x_t > 0 && !(x_t < 0 || x_t > width)) {
					pixels[(((y_t * width) + x_t) * 4) + 3] = 0;
					pixel_flags[(y_t * width) + x_t] = 0;
				}
			}	
		}
	}
}

bool PixelMap::checkHitCircle(sf::CircleShape * circle)
{
	sf::Vector2i pos = sf::Vector2i((int)(circle->getPosition().x + circle->getRadius()), (int)(circle->getPosition().y + circle->getRadius()));

	int radius = (int)circle->getRadius();
	for (int y = -radius; y <= radius; y++) {
		for (int x = -radius; x <= radius; x++) {
			if (x*x + y*y <= radius*radius) {
				int x_t = pos.x + x;
				int y_t = pos.y + y;
				if ((y_t * width) + x_t < width * height && (y_t * width) + x_t >= 0 && !(x_t < 0 || x_t >= width)) {
					if (pixel_flags[(y_t * width) + x_t]) {
						destroyCircle(x_t, y_t, radius);
						return true;
					}
				}
			}
		}
	}
	return false;
}
