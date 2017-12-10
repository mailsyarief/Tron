#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3

class MainMenu
{

public:
	MainMenu(float width, float height);
	~MainMenu();

	void draw(sf::RenderWindow &window);
	void moveup();
	void movedown();
	int GetPressedItem() { return SelectedItemIndex; }

private:
	int SelectedItemIndex;
	sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

#endif // MAINMENU_H
