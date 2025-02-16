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
	GUI* Gui;
	sf::Clock Timer;
	sf::Vector2i MousePos;
	sf::Vector2f TargetPos;
	sf::CircleShape Point;
	sf::Vector2f CenterOfView;
	sf::View GuiView;
	sf::View GameView;

	float Speed;


	void draw();
	void update(sf::Time elapsed);
	void eventHandler();

};

