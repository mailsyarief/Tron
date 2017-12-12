#include "MainMenu.h"

 MainMenu::MainMenu(float w, float h)
{
    if(!font.loadFromFile("montserrat.bold.ttf"))
    {
        printf ("Font failed to load\n");
    }

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play the games !");
    menu[0].setPosition(sf::Vector2f(w/2,h/(MAX_NUMBER_OF_ITEMS+1)*1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(w/2,h/(MAX_NUMBER_OF_ITEMS+1)*2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(w/2,h/(MAX_NUMBER_OF_ITEMS+1)*3));

}

MainMenu::~MainMenu()
{
    //dtor
}

void MainMenu::draw(sf::RenderWindow &window)
{
    for (int i=0;i<3;i++)
    {
        window.draw(menu[i]);
    }
}

void MainMenu::moveup()
{
    if (SelectedItemIndex - 1 >= 0)
    {
        menu[SelectedItemIndex].setColor(sf::Color::White);
        SelectedItemIndex ++;
        menu[SelectedItemIndex].setColor(sf::Color::Red);
    }
}

void MainMenu::movedown()
{
    if (SelectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[SelectedItemIndex].setColor(sf::Color::White);
        SelectedItemIndex --;
        menu[SelectedItemIndex].setColor(sf::Color::Red);
    }
}
