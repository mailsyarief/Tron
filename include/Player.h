#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

class Player
{
    public:
        Player(sf::Color c);
        virtual ~Player();
        void tick();
        sf::Vector3f getColor();
        int x,y,dir;
        sf::Color color;
        const int W=600;
        const int H=500;

    protected:

    private:
};

#endif // PLAYER_H
