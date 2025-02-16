#include <SFML/Graphics.hpp>

#pragma once
class Gui_Element : public sf::Drawable
{
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	virtual bool click(sf::Vector2f point) = 0;
};

