#include"mainGame.h"
#include<iostream>
mainGame::mainGame()
{
    mPosX = 194;
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
    if(mPosY+MAIN_HEIGHT>wall.y){
        mPosY=wall.y-MAIN_HEIGHT;
    }
    if(mPosY+MAIN_HEIGHT<wall.y) return false;
    return true;
}
void mainGame::handleEvent( SDL_Event& e,int WALKING_ANIMATION_FRAMES,SDL_Rect wall)
{
    if(onGround(wall))
    {
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
            if( e.key.keysym.sym== SDLK_w )
            {
                mVelY -= MAIN_VEL;
            }
        }

    if( e.type == SDL_KEYUP && e.key.repeat == 0)
    {

        if( e.key.keysym.sym==SDLK_w)
        {
            mVelY += MAIN_VEL;
        }
    }
    }
    else{
      mVelY=0;
    }
}

void mainGame::move(SDL_Rect wall)
{
    mCollider.x=mPosX;
    if(!onGround(wall))
    {
        mPosY+=3;
        mCollider.y = mPosY;
    }
    mPosY += mVelY;
    mCollider.y = mPosY;
    if( ( mPosY < 0 )|| mPosY+MAIN_HEIGHT>wall.y || mPosY+MAIN_HEIGHT<150)
    {
        mPosY -= mVelY;
        mCollider.y = mPosY;
    }
    std::cout<<mPosY<<std::endl;
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

    leftA = a.x+5;
    rightA = a.x + a.w-10;
    topA = a.y;
    bottomA = a.y + a.h-5;
    leftB = b.x+5;
    rightB = b.x + b.w-10;
    topB = b.y+10;
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





