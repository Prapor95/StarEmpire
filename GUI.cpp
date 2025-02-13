#include "GUI.h"

GUI::GUI()
{
	shape.setRadius(50);
	shape.setFillColor(sf::Color::Blue);
	shape.setPosition({ 500,800 });
	if (!GUI_Font.openFromFile("PTM55FT.ttf"))
	{
		std::cout << "Failed open fonts PTM55FT.ttf" << std::endl;
	}

	GE.push_back(new GUI_Button(&GUI_Font, "new game!!!",{50,50}));
	GE.push_back(new GUI_Button(&GUI_Font, "HELP!!!", {50,150}));
	GE.push_back(new GUI_Button(&GUI_Font, "Tima", { 250,300 }));
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

void GUI::newFunc()
{
	shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() / 255));
}

void GUI::sPos(sf::Vector2f pos)
{
	shape.setPosition(pos);
}
