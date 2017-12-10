#include "Options.h"

Options::Options(float width, float height)
{

	if (!font.loadFromFile("comicsans.ttf"))
	{
		// handle error
	}

	text.setFont(font);
	text.setColor(sf::Color::Red);
	text.setString("T R O N  G A M E !!!");
    text1.setFont(font);
    text1.setCharacterSize(15);
	text1.setColor(sf::Color::White);
	text1.setString("\n\nFinal Project PBO - Dosen : Abdul Munif");
    text1.setString("\n\nTekan Q untuk kembali ke main menu");


	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Background Music : On");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setColor(sf::Color::White);
	menu[1].setString("About");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setColor(sf::Color::White);
	menu[2].setString("View  Control");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}


Options::~Options()
{

}

void Options::draw(sf::RenderWindow &window)
{
    window.draw(text);
    window.draw(text1);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
        menu[i].setFont(font);
        menu[i].setCharacterSize(20);
		window.draw(menu[i]);
	}
}

void Options::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Options::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Options::MusicOffOn(sf::RenderWindow &window)
{
	if(menu[0].getString() == "Background Music : On")
	{
        menu[0].setString("Background Music : Off");
		window.draw(menu[0]);
	}
	else if (menu[0].getString() == "Background Music : Off")
	{
        menu[0].setString("Background Music : On");
		window.draw(menu[0]);
	}
}
