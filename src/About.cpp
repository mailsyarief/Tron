#include "About.h"

About::About(float width, float height)
{

	if (!font.loadFromFile("comicsans.ttf"))
	{
		// handle error
	}
    text.setFont(font);
    text.setCharacterSize(15);
	text.setColor(sf::Color::White);
	text.setString("\n\nTekan Q untuk kembali ke main menu");
    text.setPosition(420,650);


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
	for (int i = 0; i <3; i++)
	{
        menu[i].setFont(font);
        menu[i].setCharacterSize(20);
		window.draw(menu[i]);
	}
}
