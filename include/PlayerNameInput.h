#ifndef PLAYERNAMEINPUT_H
#define PLAYERNAMEINPUT_H

#include <SFML/Graphics.hpp>
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 3

class PlayerNameInput
{
    public:
        PlayerNameInput(float width, float height);
        virtual ~PlayerNameInput();
        void draw(sf::RenderWindow &window);
        int GetPressedItem() { return selectedItemIndex; }
        char player1name[10];
        char player2name[10];

    protected:

    private:
    	int selectedItemIndex;
        sf::Font font;
        sf::Texture texture;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
        sf::Text text;
        sf::Text text1;
};

#endif // PLAYERNAMEINPUT_H
