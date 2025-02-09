#pragma once
#include "Gui_Element.h"
class GUI_Button :
    public Gui_Element
{
public:
    GUI_Button(sf::Font* font, std::string string, sf::Vector2f pos);
    ~GUI_Button();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void set_position(sf::Vector2f);



protected:
    sf::Font* Font_ptr;
    sf::Text* Text;
    sf::RectangleShape RECT;


};

