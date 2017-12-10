#ifndef CONTROL_OPTIONS_H
#define CONTROL_OPTIONS_H
#include <SFML/Graphics.hpp>
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 2

class Control_Options
{
    public:
        Control_Options(float width, float height);
        virtual ~Control_Options();
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

#endif // CONTROL_OPTIONS_H
