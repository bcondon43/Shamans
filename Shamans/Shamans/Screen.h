#ifndef SCREEN_H
#define SCREEN_H

class Screen
{
public:
	Screen();
	~Screen();

	void render();
	void input();
	void update();
	bool isOpen();
private:
	unsigned int width;
	unsigned int height;
};

#endif