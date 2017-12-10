#ifndef BACKGROUND_AUDIO_H
#define BACKGROUND_AUDIO_H
#include <SFML/Audio.hpp>

using namespace sf;

class Background_Audio
{
    public:
        Background_Audio();
        virtual ~Background_Audio();
        int enablemusic();
        int enablebackgroundmusic();
        int buttonsound();
        bool play;

    protected:

    private:
        sf::Music music;
        sf::SoundBuffer buffer;
        sf::SoundBuffer buffer2;
        sf::Sound soundbutton;
};

#endif // BACKGROUND_AUDIO_H
