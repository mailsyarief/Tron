#ifndef ABOUT_H
#define ABOUT_H
#include <SFML/Graphics.hpp>
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 3

class About
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
        sf::Text text1;

        std::string str_input;
        sf::String text_input;
        sf::Event event;


};

#endif // ABOUT_H
