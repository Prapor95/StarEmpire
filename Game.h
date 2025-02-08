#include <SFML/Graphics.hpp>
#include "GUI.h"

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
	GUI gui;

};

