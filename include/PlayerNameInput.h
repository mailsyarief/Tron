#ifndef PLAYERNAMEINPUT_H
#define PLAYERNAMEINPUT_H


class PlayerNameInput
{
    public:
        PlayerNameInput(float width, float height);
        virtual ~PlayerNameInput();
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

#endif // PLAYERNAMEINPUT_H
