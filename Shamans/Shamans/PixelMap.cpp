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
	//TODO: Finish this function
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
	for (int i = 0; i < map.getSize().x * map.getSize().y * 4; i += 4) {
		if (pixels[i + 3] != 0b0) {
			pixels[i] = temp_pixels[i];
			pixels[i + 1] = temp_pixels[i + 1];
			pixels[i + 2] = temp_pixels[i + 2];
			pixels[i + 3] = temp_pixels[i + 3];
			pixel_flags[i / 4] = 0b00000001;
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
	for (int j = 0; j < radius; j++) {
		for (int i = 0; i < 360; i++) {
			int x = w_x + (sin((2.f * 3.14f) / i) * j);
			int y = w_y + (cos((2.f * 3.14f) / i) * j);
			if ((y * width) + x < width * height && (y * width) + x > 0) {
				pixels[(((y * width) + x) * 4) + 3] = 0;
				pixel_flags[(y * width) + x] = 0;
			}
		}
	}
}