#include"Color.h"
void Color::setColor(SDL_Texture* mTexture,Uint8 red, Uint8 green, Uint8 blue)
{
    SDL_SetTextureColorMod( mTexture, red, green, blue );
}
void Color::mixerColor(SDL_Event e){
    if( e.type == SDL_KEYDOWN )
                    {
                        switch( e.key.keysym.sym )
                        {
                            case SDLK_q:
                            r += 32;
                            break;
                            case SDLK_w:
                            g += 32;
                            break;
                            case SDLK_e:
                            b += 32;
                            break;
                            case SDLK_a:
                            r -= 32;
                            break;
                            case SDLK_s:
                            g -= 32;
                            break;
                            case SDLK_d:
                            b -= 32;
                            break;
                        }
                    }
}
