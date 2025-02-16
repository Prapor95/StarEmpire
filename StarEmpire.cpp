#include <iostream>
#include "Game.h"

int main()
{
	std::cout << "Star Empire v. 0.0.1" << std::endl << "Created by Sergey Omelchenko" << std::endl;
	Game game;
	game.init();
	game.run();
	game.end();

	std::cout << "Thank you for your attention to my project." << std::endl << "If you have any suggestions, please send them to my email address: prapor95@yandex.ru";
}

