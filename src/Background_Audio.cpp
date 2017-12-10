#include "Background_Audio.h"

Background_Audio::Background_Audio()
{

}

Background_Audio::~Background_Audio()
{
    //dtor
}

Background_Audio::enablebackgroundmusic()
{
    if (!music.openFromFile("background.wav")) return -1;
    music.play();
}

Background_Audio::disablemusic()
{
    music.stop();
}

Background_Audio::enablemusic()
{
    music.play();
}

Background_Audio::buttonsound()
{
    if (!music.openFromFile("Pop-sound-effect.wav")) return -1;
    music.play();
}
