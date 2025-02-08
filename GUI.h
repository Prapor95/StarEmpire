#include <SFML/Graphics.hpp>

#pragma once
class GUI : public sf::Drawable
{

public:
    GUI();
    ~GUI();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
    sf::CircleShape shape;
};

