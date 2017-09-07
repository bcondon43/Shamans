#ifndef PIXELMAP_H
#define PIXELMAP_H

#include <string>

class PixelMap
{
public:
	PixelMap(unsigned int scene_width, unsigned int scene_height);
	~PixelMap();

	/**
	@params takes a png file path and converts it into an array of pixels and flags
	*/
	bool load(std::string png_path);
private:

	

	unsigned int scene_width;
	unsigned int scene_height;

};

#endif