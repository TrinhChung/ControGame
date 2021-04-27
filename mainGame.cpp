#include"mainGame.h"
#include<iostream>
mainGame::mainGame()
{
    mPosX = 50;
    mPosY = 300;
    mCollider.w = MAIN_WIDTH;
    mCollider.h = MAIN_HEIGHT;
    mVelX = 0;
    mVelY = 0;
    degrees=0;
}
int mainGame::getPosX()
{
    return mPosX;
}
int mainGame::getPosY()
{
    return mPosY;
}

bool mainGame::onGround(SDL_Rect wall )
{
    bool check=true;
    if(mPosY+MAIN_HEIGHT<wall.y || mPosY+MAIN_HEIGHT>wall.y )
    {
            check=false;
    }
    return check;
}
void mainGame::setWidth_Height(int width,int height){
    MAIN_WIDTH=width;
    MAIN_HEIGHT=height;
}
void mainGame::handleEvent( SDL_Event& e,int WALKING_ANIMATION_FRAMES,SDL_Rect wall,Mix_Chunk *gMedium)
{
    if(onGround(wall))
    {
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
            if( e.key.keysym.sym== SDLK_w )
            {
                mVelY -= MAIN_VEL;
                Mix_PlayChannel( -1, gMedium, 0 );
            }
        }

    if( e.type == SDL_KEYUP && e.key.repeat == 0)
    {

        if( e.key.keysym.sym==SDLK_w)
        {
            mVelY += MAIN_VEL;
        }
    }
    if(mVelY>0){
        mVelY=0;
    }

    }
    else{
            mVelY=0;

    }
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
            if( e.key.keysym.sym== SDLK_s )
            {
                bow=true;
                Mix_PlayChannel( -1, gMedium, 0 );
                mPosY=wall.y-MAIN_HEIGHT;
                mCollider.y=mPosY;
            }
        }
    if( e.type == SDL_KEYUP && e.key.repeat == 0)
    {

        if( e.key.keysym.sym==SDLK_s&& bow)
        {
         bow=false;
         mPosY-=24;
        }
    }
}
void mainGame::setPosY(int y){
    mPosY=y;

    mCollider.y=y;
}
void mainGame::move(SDL_Rect wall,int g)
{
    mCollider.x=mPosX;
    if(mPosY<120){
        mVelY=0;
    }
    mPosY += mVelY;
    mCollider.y = mPosY;

    if(!onGround(wall) && wall.y > MAIN_HEIGHT+mPosY)
    {
        if(wall.y-mPosY-MAIN_HEIGHT<g )
        {
            mPosY++;
            mCollider.y=mPosY;
        }
        if(wall.y-mPosY-MAIN_HEIGHT>=g ){
        mPosY +=g;
        mCollider.y = mPosY;
        }
    }
    if( mPosY+MAIN_HEIGHT+mVelY>wall.y)
    {
        mPosY -= mVelY;
        mCollider.y = mPosY;
    }
}
void mainGame::render(LTexture &gFooTexture,SDL_Renderer* &gRenderer,SDL_Rect* clip)
{
    gFooTexture.render(mPosX, mPosY,gRenderer,clip,degrees,NULL,flipType);
}
bool checkCollision( SDL_Rect a, SDL_Rect b )
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = a.x+20;
    rightA = a.x + a.w*3/5;
    topA = a.y;
    bottomA = a.y + a.h;
    leftB = b.x+b.w*1/2;
    rightB = b.x + b.w*2/3;
    topB = b.y+b.w*1/7;
    bottomB = b.y + b.h;
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }
    return true;
}





