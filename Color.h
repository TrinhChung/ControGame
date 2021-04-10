#ifndef COLOR_H_
#define COLOR_H_
#include"SDL.h"
//#include"SDL_image.h"
#include"function.h"
#include"mainGame.h"
class Color{
public:
    Uint8 r = 255;
    Uint8 g = 255;
    Uint8 b = 255;
    void setColor( SDL_Texture* mTexture,Uint8 red, Uint8 green, Uint8 blue);
    void mixerColor(SDL_Event e);
};
#endif // COLOR_H_

