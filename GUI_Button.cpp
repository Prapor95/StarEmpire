#include "GUI_Button.h"

GUI_Button::GUI_Button(sf::Font* font, std::string string, sf::Vector2f pos)
{
	Font_ptr = font;
	Text = new sf::Text(*font, string);
	Text->setCharacterSize(30);
	Text->setStyle(sf::Text::Bold);
	Text->setFillColor(sf::Color::Red);
	Text->setPosition(pos);
	RECT.setSize({ 170,40 });
	RECT.setFillColor(sf::Color(50, 50, 50));
	RECT.setOutlineThickness(1);
	RECT.setOutlineColor(sf::Color::Red);
	RECT.setPosition(pos);
}

GUI_Button::~GUI_Button()
{ 

}

void GUI_Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(RECT);
	target.draw(*Text);
}

void GUI_Button::set_position(sf::Vector2f x)
{
	Text->setPosition(x);
}
