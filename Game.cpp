#include "Game.h"

Game::Game():
    Window(nullptr)
{

}

void Game::init()
{
    if (Window == nullptr)
        Window = new sf::RenderWindow(sf::VideoMode({ 1200, 1000 }), "4X TBS Lessons");
}

void Game::run()
{


    while (Window->isOpen())
    {
        while (const std::optional event = Window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                Window->close();
            }
            if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                 // update the view to the new size of the window
                 sf::FloatRect visibleArea({ 0.f, 0.f }, sf::Vector2f(resized->size));
                 Window->setView(sf::View(visibleArea));
            }

            Window->clear();
            
            Window->draw(gui);
            Window->display();
        }
    }
}

void Game::end() 
{
    if (Window != nullptr)
        delete Window;
    Window = nullptr;
}