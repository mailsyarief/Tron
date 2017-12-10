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
    play = 1;
}

Background_Audio::enablemusic()
{
    if (play == 1)
    {
        music.stop();
        play = 0;
    }
    else if (play == 0)
    {
        music.play();
        play = 1;
    }
}

Background_Audio::buttonsound()
{
    if (!buffer.loadFromFile("Pop-sound-effect.wav")) return -1;
    soundbutton.setBuffer(buffer);
    soundbutton.play();
}
