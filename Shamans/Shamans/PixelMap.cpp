#include "PixelMap.h"
#include "SFML\Graphics.hpp"


PixelMap::PixelMap(unsigned int scene_width, unsigned int scene_height)
{
	PixelMap::scene_width = scene_width;
	PixelMap::scene_height = scene_height;
}


PixelMap::~PixelMap()
{
}


bool PixelMap::load(std::string png_path) {
	//TODO: Finish this function
	sf::Image map;
	map.loadFromFile(png_path);
	return true;
}