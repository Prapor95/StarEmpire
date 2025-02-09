#include "GUI.h"

GUI::GUI()
{
	shape.setRadius(30);
	shape.setFillColor(sf::Color::Green);
	if (!GUI_Font.openFromFile("PTM55FT.ttf"))
	{
		std::cout << "Failed open fonts PTM55FT.ttf" << std::endl;
	}

	GE.push_back(new GUI_Button(&GUI_Font, "HELLO!!!",{50,50}));
	GE.push_back(new GUI_Button(&GUI_Font, "HELP!!!", {50,150}));

}

GUI::~GUI()
{

}

void GUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape);
	for (Gui_Element* n : GE)
	{
		target.draw(*n);
	}
	//target.draw(*GE[0]);
}
