#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"
#define MAX_NUMBER_OF_ITEMS 4

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Texture texture;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Text text;
    sf::Text text1;
    sf::Sprite imageSprite;

};

#endif // MENU_H
