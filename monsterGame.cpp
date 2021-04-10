#include"monsterGame.h"
monsterGame::monsterGame(){
    tCollider.h=MON_HEIGHT;
    tCollider.w=MON_WIDTH;
    tPosX=0;
    tPosY=10;
}
monsterGame::~monsterGame(){
}
int monsterGame::getPosX(){
    return tPosX;
}
void monsterGame::render(LTexture &gFooTexture,SDL_Renderer* &gRenderer,SDL_Rect* clip){
    gFooTexture.render(tPosX , tPosY,gRenderer,clip,0,NULL,flipType);
}
void monsterGame::setPosX(int PosX){
    tPosX=PosX;
}
void monsterGame::setWidth_Height(int width,int height){
    MON_WIDTH =width;
    MON_HEIGHT=height;
    tCollider.h=MON_HEIGHT;
    tCollider.w=MON_WIDTH;
}

void monsterGame::setPosY(SDL_Rect wall,int val_Y){
    tPosY=wall.y-MON_HEIGHT-val_Y;
}
bool monsterGame::move(int scrollingOffset,mainGame bossGame){
    bool check = true;
    if(!checkCollision(bossGame.mCollider,tCollider))
    {
       if(tPosX+MON_WIDTH==0)
       {
         tPosX=1280;
        }
       tPosX-=2;
       tCollider.x=tPosX;
       tCollider.y=tPosY;
    }
    else
    {
        tPosX+=2;
        tCollider.x=tPosX;
        check=false;
    }
    return check;
}
