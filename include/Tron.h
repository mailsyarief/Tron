#ifndef TRON_H
#define TRON_H
#include <SFML/Graphics.hpp>
#include <time.h>

class Tron
{
    public:
        Tron(Color c);
        virtual ~Tron();
        void tick();
        sf::Vector3f getColor();

    protected:

    private:
        int x,y,dir;

};

#endif // TRON_H

struct player
{ int x,y,dir;
  Color color;
  player(Color c)
  {
    x=rand() % W;
    y=rand() % H;
    color=c;
    dir=rand() % 4;
  }
  void tick()
  {
    if (dir==0) y+=1;
    if (dir==1) x-=1;
    if (dir==2) x+=1;
    if (dir==3) y-=1;

	if (x>=W) x=0;  if (x<0) x=W-1;
    if (y>=H) y=0;  if (y<0) y=H-1;
  }

  Vector3f getColor()
  {return Vector3f(color.r,color.g,color.b);}
};
