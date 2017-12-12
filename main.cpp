#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include <cstring>
#include <sstream>

#include "About.h"
#include "Background_Audio.h"
#include "MainMenu.h"
#include "Menu.h"
#include "Options.h"
#include "Player.h"
#include "Control_Options.h"
#include "PlayerNameInput.h"

using namespace sf;

Background_Audio background;
const int W=1080;
const int H=720;
float speed;
int scoreA,scoreB;
bool field[W][H]={0};

void a();
void MainMenu();
void OptionsFunction();
void AboutFunction();
void ControlFunction();

void a()
{
    speed = 1;
    memset(field,0,sizeof(field));
    srand(time(0));

    RenderWindow window(VideoMode(W, H), "Alhamdullilah kelar");
    window.setFramerateLimit(60);

	sf::Texture texture;
	texture.loadFromFile("background_ingame.jpg");
	sf::Sprite sBackground(texture);

    Player p1(Color::Red), p2(Color::White);

	Sprite sprite;
	RenderTexture t;
	t.create(W, H);
	t.setSmooth(true);
	sprite.setTexture(t.getTexture());
    t.clear();
    t.draw(sBackground);

	sf::Font font;
    if (!font.loadFromFile("comicsans.ttf")) printf("Loading font failed\n");
    Text text("YOU WIN!",font,50);
	text.setPosition(W/2-90,H/2-40);

    Text text2("Tekan Q untuk keluar, Tekan R untuk restart game",font,20);
    text2.setPosition(300,600);

    Text text3("Player 1 Color : White | Player 2 Color : Red",font,18);
    text3.setPosition(W-500,H-30);

    Text text4("B = Game speed - 1 | N = Game Speed + 1",font,18);
    text4.setPosition(W-1000,H-30);

    sf:Font comicsans;
    comicsans.loadFromFile("comicsans.ttf");

    std::ostringstream ssScore;
    ssScore << "red : " << scoreA << " | white : " <<scoreB;

    sf::Text lblScore;
    lblScore.setCharacterSize(18);
    lblScore.setPosition({ 10, 10 });
    lblScore.setFont(comicsans);
    lblScore.setString(ssScore.str());

	bool Game=1;

	Shader* shader = new Shader;
	shader->loadFromFile("shader.frag",Shader::Fragment);
	shader->setParameter("frag_ScreenResolution", Vector2f(W,H));
	shader->setParameter("frag_LightAttenuation", 100);
	RenderStates states;
	states.shader = shader;
    //game mulai
    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            if (p1.statusarah != 2 && p1.statusarah != 3)background.buttonsound();
            if (p1.dir!=2) p1.dir=1;
        }
	    if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            if (p1.statusarah != 3 && p1.statusarah != 2)background.buttonsound();
            if (p1.dir!=1)  p1.dir=2;
        }
	    if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            if (p1.statusarah != 1 && p1.statusarah != 4)background.buttonsound();
            if (p1.dir!=0) p1.dir=3;
        }
		if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            if (p1.statusarah != 4 && p1.statusarah != 1)background.buttonsound();
            if (p1.dir!=3) p1.dir=0;
        }
		if (Keyboard::isKeyPressed(Keyboard::A))
        {
            if (p2.statusarah != 2 && p2.statusarah != 3)background.buttonsound();
            if (p2.dir!=2) p2.dir=1;
        }
	    if (Keyboard::isKeyPressed(Keyboard::D))
        {
            if (p2.statusarah != 3 && p2.statusarah !=2)background.buttonsound();
            if (p2.dir!=1)  p2.dir=2;
        }
	    if (Keyboard::isKeyPressed(Keyboard::W))
        {
            if (p2.statusarah != 1 && p2.statusarah != 4)background.buttonsound();
            if (p2.dir!=0) p2.dir=3;
        }
		if (Keyboard::isKeyPressed(Keyboard::S))
        {
            if (p2.statusarah != 4 && p2.statusarah != 1)background.buttonsound();
            if (p2.dir!=3) p2.dir=0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Q))
        {
            system("CLS");
            scoreA = 0;
            scoreB = 0;

            background.buttonsound();
            window.clear();
            window.close();
            MainMenu();
        }
        if (Keyboard::isKeyPressed(Keyboard::R))
        {
            window.clear();
            window.close();
            a();
        }
        if(Keyboard::isKeyPressed(Keyboard::B))
        {
            if(speed>0.1)
                speed-=0.1;
        }
        if(Keyboard::isKeyPressed(Keyboard::N))
        {
            if(speed<3)
                speed+=0.1;
        }

		if (!Game)
        {
            background.buttonsound();
            window.draw(text);
            window.draw(text2);
            window.display();
            continue;
        }

		for(int i=0;i<speed;i++)
		{
			p1.tick(); p2.tick();
			if (field[p1.x][p1.y]==1) {Game=0; text.setColor(p2.color); text2.setColor(sf::Color::White);
                printf("Red = %d | White = %d\n", scoreA, ++scoreB);
			}
			if (field[p2.x][p2.y]==1) {Game=0; text.setColor(p1.color); text2.setColor(sf::Color::White);
                printf("Red = %d | White = %d\n", ++scoreA, scoreB);
			}
			field[p1.x][p1.y]=1;
			field[p2.x][p2.y]=1;

            t.display();

			shader->setParameter("frag_LightOrigin", Vector2f(p1.x,p1.y));
			shader->setParameter("frag_LightColor",p1.getColor());
			t.draw(sprite, states);
			shader->setParameter("frag_LightOrigin", Vector2f(p2.x,p2.y));
			shader->setParameter("frag_LightColor",p2.getColor());
			t.draw(sprite, states);
		}
	   ////// draw  ///////
		window.clear();
		window.draw(sprite);
		window.draw(text3);
		window.draw(text4);
		window.draw(lblScore);
 		window.display();

	}

}

void MainMenu()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(W, H), "TRON");
	Menu menu(window.getSize().x, window.getSize().y);

    sf::Texture imageSource;
    if(!imageSource.loadFromFile("title.jpg")) printf("Load Background  Failed\n");
    sf::Sprite imageSprite;
    imageSprite.setTexture(imageSource);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
				    background.buttonsound();
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
				    background.buttonsound();
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
					    background.buttonsound();
						window.clear();
						window.close();
						a();
						break;
					case 1:
					    background.buttonsound();
                        window.clear();
                        window.close();
						OptionsFunction();
						break;
					case 2:
					    background.buttonsound();
						window.close();
						break;
					}

					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
        window.draw(imageSprite);
		menu.draw(window);
		window.display();
	}
}

void OptionsFunction()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(W, H), "TRON");
	Options menu(window.getSize().x, window.getSize().y);

    sf::Texture imageSource;
    if(!imageSource.loadFromFile("title.jpg")) printf("Load Background  Success");
    sf::Sprite imageSprite;
    imageSprite.setTexture(imageSource);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
                case sf::Keyboard::Q:
                        background.buttonsound();
                        window.clear();
						window.close();
						MainMenu();
						break;

				case sf::Keyboard::Up:
				    background.buttonsound();
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
				    background.buttonsound();
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						background.enablemusic();
                        menu.MusicOffOn(window);
                        window.display();
						break;
					case 1:
					    background.buttonsound();
                        window.clear();
						window.close();
						AboutFunction();
						break;
					case 2:
					    background.buttonsound();
                        window.clear();
                        window.close();
						ControlFunction();
						break;
					}

					break;
				}
				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}
		window.clear();
		window.draw(imageSprite);
		menu.draw(window);
		window.display();
	}
}

void AboutFunction()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(W, H), "TRON");
	About menu(window.getSize().x, window.getSize().y);

    sf::Texture imageSource;
    if(!imageSource.loadFromFile("title.jpg")) printf("Load Background  Success");
    sf::Sprite imageSprite;
    imageSprite.setTexture(imageSource);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Q:
				    background.buttonsound();
				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
					    background.buttonsound();
						window.clear();
						window.close();
						MainMenu();
						break;
					}
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		window.draw(imageSprite);
		menu.draw(window);
		window.display();
	}
}

void ControlFunction()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(W, H), "TRON");
	Control_Options menu123(window.getSize().x, window.getSize().y);

    sf::Texture imageSource;
    if(!imageSource.loadFromFile("title.jpg")) printf("Load Background  Success");
    sf::Sprite imageSprite;
    imageSprite.setTexture(imageSource);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Q:
				    background.buttonsound();

				case sf::Keyboard::Return:
					switch (menu123.GetPressedItem())
					{
					case 0:
						window.clear();
						window.close();
						MainMenu();
						break;
					}
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		window.draw(imageSprite);
		menu123.draw(window);
		window.display();
	}
}

int main()
{
    background.enablebackgroundmusic();
    MainMenu();
    return 0;
}
