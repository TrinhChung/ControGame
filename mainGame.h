#ifndef MAINGAME_H_
#define MAINGAME_H_
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<string>
#include<vector>
#include<SDL_ttf.h>
#include"function.h"
class mainGame
{
    public:
        SDL_RendererFlip flipType = SDL_FLIP_NONE;
        int MAIN_WIDTH=81;
        int MAIN_HEIGHT=100;
        static const int MAIN_VEL = 10;
        double degrees;
        mainGame();
        bool bow=false;
        void render(LTexture &gFooTexture,SDL_Renderer* &gRenderer,SDL_Rect* clip);
        void handleEvent( SDL_Event& e ,int WALKING_ANIMATION_FRAMES,SDL_Rect wall,Mix_Chunk *gMedium);
        void move(SDL_Rect wall,int g);
        void setWidth_Height(int Width,int Height);
        void setPosY(int y);
        int getPosX();
        int getPosY();
        bool onGround(SDL_Rect wall);
        SDL_Rect mCollider;
        private:
        int mPosX, mPosY;
        int mVelX, mVelY;

};
bool checkCollision( SDL_Rect a, SDL_Rect b );
#endif // MAINGAME_H_
