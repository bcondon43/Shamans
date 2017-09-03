
#include "Screen.h"
#define WIDTH 800
#define HEIGHT 600
#define TITLE "Shamans"

int main() {
	Screen screen(WIDTH, HEIGHT, TITLE);

	while (screen.isOpen())
	{
		screen.input();
		screen.update();
		screen.render();
	}
}