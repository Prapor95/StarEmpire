#include "Game.h"

Game::Game():
    Window(nullptr)
{

}

void Game::init()
{
    if (Window == nullptr)
        Window = new sf::RenderWindow(sf::VideoMode({ 200, 200 }), "4X TBS Lessons");
}

void Game::run()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (Window->isOpen())
    {
        while (const std::optional event = Window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                Window->close();
        }

        Window->clear();
        Window->draw(shape);
        Window->display();
    }
}

void Game::end() {
    if (Window != nullptr)
        delete Window;
    Window = nullptr;
}