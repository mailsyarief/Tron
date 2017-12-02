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
        int disablemusic();

    protected:

    private:
        sf::Music music;
};

#endif // BACKGROUND_AUDIO_H
