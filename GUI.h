#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "GUI_Button.h"
#include <random>


#include "Gui_Element.h"

#pragma once
class GUI : public sf::Drawable
{

public:
    GUI();
    ~GUI();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void newFunc();
    void sPos(sf::Vector2f);
protected:
    sf::CircleShape shape;
    std::vector <Gui_Element*> GE;
    sf::Font GUI_Font;
};

