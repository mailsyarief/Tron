#include "MenuLayout.h"

MenuLayout::MenuLayout()
{
	if(!imagesource.loadFromFile("title.jpg"))
	{
		printf("Load Background  Failed");
	}

    default_background.setTexture(imagesource);

	if (!font.loadFromFile("comicsans.ttf"))
	{
		// handle error
	}

    text.setFont(font);
    text.setCharacterSize(15);
	text.setColor(sf::Color::White);
	text.setString("\n\nTekan Q Untuk Kembali ke Menu Awal ");
	text.setPosition(420,650);

    selectedItemIndex = 0;
}

MenuLayout::~MenuLayout()
{
    //dtor
}

void MenuLayout::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Cyan);
	}
}

void MenuLayout::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Cyan);
	}
}
