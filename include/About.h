#ifndef ABOUT_H
#define ABOUT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <MenuLayout.h>

class About : public MenuLayout
{
    public:
        About(float width, float height);
        virtual ~About();
        void draw(sf::RenderWindow &window);
        int GetPressedItem() { return selectedItemIndex; }

    protected:

    private:
    	int selectedItemIndex;
        sf::Font font;
        sf::Texture texture;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
        sf::Text text;

        std::string str_input;
        sf::String text_input;
        sf::Event event;


};

#endif // ABOUT_H
