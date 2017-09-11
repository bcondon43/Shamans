#ifndef PIXELMAP_H
#define PIXELMAP_H

#include <string>
#include <SFML\Graphics.hpp>

class PixelMap
{
public:
	PixelMap();
	~PixelMap();

	/**
	@params takes a png file path and converts it into an array of pixels and flags
	@returns success or failure
	*/
	bool load(std::string png_path);
	sf::Uint8* getPixels();
	int getWidth();
	int getHeight();
	void destroyCircle(int w_x, int w_y, int radius);
private:
	int width;
	int height;
	sf::Uint8* pixels;
	char* pixel_flags;
};

#endif