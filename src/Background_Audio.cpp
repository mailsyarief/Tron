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

Background_Audio::enablemusic()
{
    if (!music.openFromFile("background.wav")) music.play();
    if (music.openFromFile("background.wav")) music.stop();
}

Background_Audio::buttonsound()
{
    if (!buffer.loadFromFile("Pop-sound-effect.wav")) return -1;
    soundbutton.setBuffer(buffer);
    soundbutton.play();
}
