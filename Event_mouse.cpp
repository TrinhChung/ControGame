/*#include"Event_mouse.h"
#include"mainGame.h"
void keyEventBoard::walk(SDL_Event e,int WALKING_ANIMATION_FRAMES,int &x,int &y){
    if( e.type == SDL_KEYDOWN )
            {
            switch( e.key.keysym.sym )
            {
                            case SDLK_UP:
                            y-= 32;
                            fame++;
                            break;
                            case SDLK_DOWN:
                            y+= 32;
                            fame++;
                            break;
                            case SDLK_RIGHT:
                            x+= 32;
                            flipType=SDL_FLIP_NONE;
                            fame++;
                            break;
                            case SDLK_LEFT:
                            x-= 32;
                            fame++;
                            flipType=SDL_FLIP_NONE;
                            break;

                        }
           if(flipType==SDL_FLIP_HORIZONTAL){
             switch( e.key.keysym.sym )
            {
                 case SDLK_RIGHT:
                    flipType=SDL_FLIP_NONE;

            }
           }
           if(flipType==SDL_FLIP_NONE){
             switch( e.key.keysym.sym )
            {
                 case SDLK_LEFT:
                    flipType=SDL_FLIP_HORIZONTAL;
            }
           }
    }
    if(fame>=WALKING_ANIMATION_FRAMES){
        fame=fame%WALKING_ANIMATION_FRAMES;
    }
}*/
