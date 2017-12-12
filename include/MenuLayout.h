#ifndef MENULAYOUT_H
#define MENULAYOUT_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#define MAX_NUMBER_OF_ITEMS 3

using namespace sf;

class MenuLayout
{
  protected:
  	int selectedItemIndex;
  	sf::Text menu[MAX_NUMBER_OF_ITEMS];
  	sf::Font font;
  	sf::Text text;
    sf::Texture imagesource;

  public:
    MenuLayout();
    ~MenuLayout();

		void MoveUp();
		void MoveDown();
		int GetPressedItem() { return selectedItemIndex; }
    sf::Sprite default_background;

};

#endif // MENULAYOUT_H
