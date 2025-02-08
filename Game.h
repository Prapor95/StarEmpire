#include <SFML/Graphics.hpp>

#pragma once
class Game
{
public:
	Game();
	void init();
	void run();
	void end();
	enum class State { Run, Pause, Close, Menu};


protected:
	sf::RenderWindow* Window;

};

