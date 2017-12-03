#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>

#include "Menu.h"
#include "Background_Audio.h"
#include "Options.h"
#include "About.h"
#include "Player.h"


using namespace sf;

Background_Audio background;
const int W=600;
const int H=500;
int speed = 1;
bool field[W][H]={0};

void a();
void MainMenu();
void OptionsFunction();
void AboutFunction();


void a()
{
    srand(time(0));

    RenderWindow window(VideoMode(W, H), "The Tron!");
    window.setFramerateLimit(60);

	sf::Texture texture;
	texture.loadFromFile("background.jpg");
	sf::Sprite sBackground(texture);

    Player p1(Color::Yellow), p2(Color::Cyan);

	Sprite sprite;
	RenderTexture t;
	t.create(W, H);
	t.setSmooth(true);
	sprite.setTexture(t.getTexture());
    t.clear();
    t.draw(sBackground);

	sf::Font font;
    if (!font.loadFromFile("Sansation_Regular.ttf"))
    {
        // error...
    }
    Text text("YOU WIN!",font,35);
	text.setPosition(W/2-80,20);

    Text text2("press Q = quit, press R = restart",font,35);
    text2.setPosition(W/2-H/2,H/2+140);

	bool Game=1;

	Shader* shader = new Shader;
	shader->loadFromFile("shader.frag",Shader::Fragment);
	shader->setParameter("frag_ScreenResolution", Vector2f(W,H));
	shader->setParameter("frag_LightAttenuation", 100);
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

		if (Keyboard::isKeyPressed(Keyboard::Left)) if (p1.dir!=2)
        {
            p1.dir=1;
            sf::Music music;
            if (!music.openFromFile("effect.wav")) // error
            music.play();
        }
	    if (Keyboard::isKeyPressed(Keyboard::Right)) if (p1.dir!=1)  p1.dir=2;
	    if (Keyboard::isKeyPressed(Keyboard::Up)) if (p1.dir!=0) p1.dir=3;
		if (Keyboard::isKeyPressed(Keyboard::Down)) if (p1.dir!=3) p1.dir=0;

		if (Keyboard::isKeyPressed(Keyboard::A)) if (p2.dir!=2) p2.dir=1;
	    if (Keyboard::isKeyPressed(Keyboard::D)) if (p2.dir!=1)  p2.dir=2;
	    if (Keyboard::isKeyPressed(Keyboard::W)) if (p2.dir!=0) p2.dir=3;
		if (Keyboard::isKeyPressed(Keyboard::S)) if (p2.dir!=3) p2.dir=0;

        if (Keyboard::isKeyPressed(Keyboard::Q))
        {
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

		if (!Game)
        {
            window.draw(text);
            window.draw(text2);
            window.display();
            continue;
        }

		for(int i=0;i<speed;i++)
		{
			p1.tick(); p2.tick();
			if (field[p1.x][p1.y]==1) {Game=0; text.setColor(p2.color); text2.setColor(p2.color);}
			if (field[p2.x][p2.y]==1) {Game=0; text.setColor(p1.color); text2.setColor(p1.color);}
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
 		window.display();
	}

}

void MainMenu()
{

    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(600, 600), "TRON");
	Menu menu(window.getSize().x, window.getSize().y);

    sf::Texture texture;
	texture.loadFromFile("background.jpg");
	Sprite BBackground(texture);

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
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
						window.clear();
						window.close();
						a();
						break;
					case 1:
						std::cout << "Options button has been pressed" << std::endl;
                        window.clear();
                        window.close();
						OptionsFunction();
						break;
					case 2:
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

		RenderTexture bg;
		bg.draw(BBackground);

		window.clear();
		menu.draw(window);
		window.display();
	}
}

void OptionsFunction()
{

    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(600, 600), "TRON");
	Options menu(window.getSize().x, window.getSize().y);

    sf::Texture texture;
	texture.loadFromFile("background.jpg");
	Sprite sBackground(texture);

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
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
                        background.disablemusic();
						break;
					case 1:
						std::cout << "About button has been pressed" << std::endl;
                        window.clear();
						window.close();
						AboutFunction();
						break;
					case 2:
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
		menu.draw(window);
		window.display();
	}
}

void AboutFunction()
{

    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(600, 600), "TRON");
	About menu(window.getSize().x, window.getSize().y);

    sf::Texture texture;
	texture.loadFromFile("background.jpg");
	Sprite sBackground(texture);

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
                    std::cout<< "Back to Main Menu"<< std::endl;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
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
		menu.draw(window);
		window.display();
	}
}

int main()
{
    background.enablebackgroundmusic();
    MainMenu();

}
