#ifndef ABILITYBAR_H
#define ABILITYBAR_H
class AbilityBar
{
public:
	AbilityBar();
	~AbilityBar();

	/**
	loades abilities from a file
	@params filepath
	*/
	void load(char* filepath);
	void input();
	void render();
private:
	
};

#endif