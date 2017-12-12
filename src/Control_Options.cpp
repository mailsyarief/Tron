#include "Control_Options.h"

Control_Options::Control_Options(float width, float height)
{

	if (!font.loadFromFile("comicsans.ttf"))
	{
		// handle error
	}

	text.setFont(font);
	text.setColor(sf::Color::Red);
	text.setString("");
    text1.setFont(font);
    text1.setCharacterSize(15);
	text1.setColor(sf::Color::White);
	text1.setString("\n\nTekan Q untuk kembali ke main menu");
    text1.setPosition(420,650);


	menu[0].setColor(sf::Color::White);
	menu[0].setString("Player Putih\n    W = Atas\n    S = Bawah\n    A=Kiri\n    D=Kanan\n *Hold untuk rem");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setColor(sf::Color::Red);
	menu[1].setString("Player Merah\n    Up = Atas\n    Down = Bawah\n    Left = Kiri\n    Right = Kanan\n *Hold untuk rem");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));


	selectedItemIndex = 0;
}


Control_Options::~Control_Options()
{

}

void Control_Options::draw(sf::RenderWindow &window)
{
    window.draw(text);
    window.draw(text1);
	for (int i = 0; i <2; i++)
	{
        menu[i].setFont(font);
        menu[i].setCharacterSize(20);
		window.draw(menu[i]);
	}
}
