#include "GUI.h"

GUI::GUI()
{
	shape.setRadius(30);
	shape.setFillColor(sf::Color::Green);

}

GUI::~GUI()
{

}

void GUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape);
}
