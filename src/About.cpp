#include "About.h"

About::About(float width, float height)
{

	if (!font.loadFromFile("comicsans.ttf"))
	{
		// handle error
	}

	text.setFont(font);
	text.setColor(sf::Color::Cyan);
	text.setString("");
    text1.setFont(font);
    text1.setCharacterSize(15);
	text1.setColor(sf::Color::White);
	text1.setString("\n\nFinal Project PBO - Dosen : Abdul Munif");
	text1.setString("\n\nTekan Q untuk kembali ke main menu");


	menu[0].setColor(sf::Color::White);
	menu[0].setString("5116100151 Falah Razzaq");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setColor(sf::Color::White);
	menu[1].setString("5116100164 Hilmi Raditya");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setColor(sf::Color::White);
	menu[2].setString("5116100168 Ismail Syarief");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}


About::~About()
{

}

void About::draw(sf::RenderWindow &window)
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
