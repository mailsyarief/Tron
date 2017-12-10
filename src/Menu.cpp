#include "Menu.h"

Menu::Menu(float width, float height)
{

	if (!font.loadFromFile("comicsans.ttf"))
	{
		// handle error
	}


    if(!texture.loadFromFile("title.jpg"))
    {
        //handle error
    }

    imageSprite.setTexture(texture);

	text.setFont(font);
	text.setColor(sf::Color::Cyan);
	text.setString(" ");
    text1.setFont(font);
    text1.setCharacterSize(15);
	text1.setColor(sf::Color::White);
	text1.setString("\n\nFinal Project PBO - Dosen : Abdul Munif");

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Cyan);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	selectedItemIndex = 0;
}


Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
    window.draw(text);
    window.draw(text1);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{

        menu[i].setCharacterSize(20);
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Cyan);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Cyan);
	}
}
