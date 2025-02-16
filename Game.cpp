#include "Game.h"

Game::Game():
    Window(nullptr)
    
{
    Point.setRadius(5);
    Point.setFillColor(sf::Color::Yellow);
    Point.setPosition({ 500,600 });
    Speed = 25.0;
}

void Game::init()
{
    if (Window == nullptr)
        Window = new sf::RenderWindow(sf::VideoMode({ 1200, 1000 }), "Star Empire v.0.0.1");
    GuiView = Window->getView();
    Gui = new GUI(*Window, GuiView );
    Window->setFramerateLimit(60);
    GameView = GuiView = Window->getView();
    CenterOfView = Window->getView().getCenter();
    Timer.start();
}

void Game::run()
{
    while (Window->isOpen())
    {
        this->eventHandler();
        this->update(Timer.restart());
        this->draw();
    }
}

void Game::end() 
{
    if (Window != nullptr)
        delete Window;
    Window = nullptr;
}

void Game::draw()
{
    Window->clear();
    GameView.setCenter(CenterOfView);
    Window->setView(GameView);
    Window->draw(Point);
    Window->setView(GuiView);
    Window->draw(*Gui);

    Window->display();
}

void Game::update(sf::Time elapsed)
{
    MousePos = sf::Mouse::getPosition(*Window);
    //TargetPos.x = MousePos.x;
    //TargetPos.y = MousePos.y;
    TargetPos = Window->mapPixelToCoords(sf::Mouse::getPosition(*Window), GameView);
    sf::Vector2f vect = TargetPos - Point.getPosition();
    sf::Vector2f nvect = vect.normalized();
    sf::Vector2f move = sf::Vector2f({ Speed * elapsed.asSeconds() * nvect.x,Speed * elapsed.asSeconds() * nvect.y });
    sf::Vector2f newPos = Point.getPosition() + move;
    Point.setPosition(newPos);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        CenterOfView.x += -5.0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        CenterOfView.x += 5.0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        CenterOfView.y += -5.0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        CenterOfView.y += 5.0;
    }

}

void Game::eventHandler()
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
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            if (!Gui->guiClick())
            {

            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
        {
           // Gui.sPos(Window->mapPixelToCoords(sf::Mouse::getPosition(*Window), GuiView));
        }






    }
}

