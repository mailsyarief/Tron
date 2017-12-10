#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
<<<<<<< HEAD
#include <memory>
#include <cstring>
#include "Menu.h"
=======

#include "About.h"
>>>>>>> ad3f9f39e524860506235211a45e99ef6dc9d3d6
#include "Background_Audio.h"
#include "MainMenu.h"
#include "Menu.h"
#include "Options.h"
#include "Player.h"
<<<<<<< HEAD
=======
#include "Control_Options.h"
#include "PlayerNameInput.h"
>>>>>>> ad3f9f39e524860506235211a45e99ef6dc9d3d6

using namespace sf;

Background_Audio background;
const int W=1080;
const int H=720;
<<<<<<< HEAD
float speed;
int scoreA, scoreB;
=======
int speed = 1;
>>>>>>> ad3f9f39e524860506235211a45e99ef6dc9d3d6
bool field[W][H]={0};

void a();
void MainMenu();
void OptionsFunction();
void AboutFunction();
<<<<<<< HEAD
=======
void ControlFunction();
>>>>>>> ad3f9f39e524860506235211a45e99ef6dc9d3d6

void a()
{
    speed = 0.5;
    memset(field,0,sizeof(field));
    srand(time(0));

    RenderWindow window(VideoMode(W, H), "The Tron!");
    window.setFramerateLimit(60);

	sf::Texture texture;
	texture.loadFromFile("background-1.jpg");
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
<<<<<<< HEAD
    if (!font.loadFromFile("Sansation_Regular.ttf"))
    {
        // error...
    }
    Text text("BLUE WIN!",font,35);
	text.setPosition(W/2-80,20);

    Text text2("Q = quit  |   R = Restart",font,35);
    text2.setPosition(W/2-110,H/2+140);

    Text text3("Space = Game Speed++  |   B = Game Speed--",font,35);
    text3.setPosition(W-500,H-30);

=======
    if (!font.loadFromFile("comicsans.ttf")) printf("Loading font failed\n");
    Text text("YOU WIN!",font,35);
	text.setPosition(W/2-80,20);

    Text text2("Tekan Q untuk keluar, Tekan R untuk restart game",font,20);
    text2.setPosition(W-550,H-60);

    Text text3("Player 1 Color : White | Player 2 Color : Red",font,18);
    text3.setPosition(W-500,H-30);
>>>>>>> ad3f9f39e524860506235211a45e99ef6dc9d3d6

	bool Game=1;

	Shader* shader = new Shader;
	shader->loadFromFile("shader.frag",Shader::Fragment);
	shader->setParameter("frag_ScreenResolution", Vector2f(W,H));
	shader->setParameter("frag_LightAttenuation", 100.0);
	RenderStates states;
	states.shader = shader;

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
            background.buttonsound();
            if (p1.dir!=2) p1.dir=1;
        }
	    if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            background.buttonsound();
            if (p1.dir!=1)  p1.dir=2;
        }
	    if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            background.buttonsound();
            if (p1.dir!=0) p1.dir=3;
        }
		if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            background.buttonsound();
            if (p1.dir!=3) p1.dir=0;
        }
		if (Keyboard::isKeyPressed(Keyboard::A))
        {
            background.buttonsound();
            if (p2.dir!=2) p2.dir=1;
        }
	    if (Keyboard::isKeyPressed(Keyboard::D))
        {
            background.buttonsound();
            if (p2.dir!=1)  p2.dir=2;
        }
	    if (Keyboard::isKeyPressed(Keyboard::W))
        {
            background.buttonsound();
            if (p2.dir!=0) p2.dir=3;
        }
		if (Keyboard::isKeyPressed(Keyboard::S))
        {
            background.buttonsound();
            if (p2.dir!=3) p2.dir=0;
        }
<<<<<<< HEAD

=======
>>>>>>> ad3f9f39e524860506235211a45e99ef6dc9d3d6
        if (Keyboard::isKeyPressed(Keyboard::Q))
        {
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

	    if (Keyboard::isKeyPressed(Keyboard::Right)) if (p1.dir!=1)  p1.dir=2;
	    if (Keyboard::isKeyPressed(Keyboard::Up)) if (p1.dir!=0) p1.dir=3;
		if (Keyboard::isKeyPressed(Keyboard::Down)) if (p1.dir!=3) p1.dir=0;

		if (Keyboard::isKeyPressed(Keyboard::A)) if (p2.dir!=2) p2.dir=1;
	    if (Keyboard::isKeyPressed(Keyboard::D)) if (p2.dir!=1)  p2.dir=2;
	    if (Keyboard::isKeyPressed(Keyboard::W)) if (p2.dir!=0) p2.dir=3;
		if (Keyboard::isKeyPressed(Keyboard::S)) if (p2.dir!=3) p2.dir=0;

		if (Keyboard::isKeyPressed(Keyboard::Space)) if(speed<=3) speed+=0.1;
		if (Keyboard::isKeyPressed(Keyboard::B)) if(speed>0.1) speed-=0.1;

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

			p1.tick();
			p2.tick();

			if (field[p1.x][p1.y]==1)
                {Game=0; text.setColor(p2.color); text2.setColor(p2.color);
                    printf("p1 == %d %d\n",field[p1.x][p2.y]);
                    scoreA++;
                }
			if (field[p2.x][p2.y]==1)
                {Game=0; text.setColor(p1.color); text2.setColor(p1.color);
                    printf("p2 == %d %d\n",field[p2.x][p2.y]);
                    scoreB++;
                }
			field[p1.x][p1.y]=1;
			field[p2.x][p2.y]=1;

            t.display();
            //SHADER UNTUK PLAYER//
			shader->setParameter("frag_LightOrigin", Vector2f(p1.x,p1.y));
			shader->setParameter("frag_LightColor",p1.getColor());
			t.draw(sprite, states);
			shader->setParameter("frag_LightOrigin", Vector2f(p2.x,p2.y));
			shader->setParameter("frag_LightColor",p2.getColor());
			t.draw(sprite, states);
<<<<<<< HEAD


		}

=======
		}
>>>>>>> ad3f9f39e524860506235211a45e99ef6dc9d3d6
	   ////// draw  ///////


		window.clear();
        window.draw(text3);
		window.draw(sprite);
		window.draw(text3);
 		window.display();

	}

}

void MainMenu()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(W, H), "TRON");
	Menu menu(window.getSize().x, window.getSize().y);

    sf::Texture imageSource;
    if(!imageSource.loadFromFile("background.jpg")) printf("Load Background  Failed\n");
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
    if(!imageSource.loadFromFile("background.jpg")) printf("Load Background  Success");
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
    if(!imageSource.loadFromFile("background.jpg")) printf("Load Background  Success");
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
    if(!imageSource.loadFromFile("background.jpg")) printf("Load Background  Success");
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
