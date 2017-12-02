#ifndef OPTIONS_H
#define OPTIONS_H

#include "SFML/Graphics.hpp"
#include "Background_Audio.h"
#define MAX_NUMBER_OF_ITEMS 3

class Options
{
public:
	Options(float width, float height);
	~Options();

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

};


#endif // OPTIONS_H
