#include"monsterGame.h"
monsterGame::monsterGame(){
    tCollider.h=MON_HEIGHT;
    tCollider.w=MON_WIDTH;
    tPosX=-500;
    tPosY=1280;
    monsterVel=3;
    collision=false;
    monBack=false;
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
void monsterGame::setVel(int vel){
    monsterVel=vel;
}
void monsterGame::setPosY(SDL_Rect wall,int val_Y){
    tPosY=wall.y-MON_HEIGHT-val_Y;
}
void monsterGame::returnMon(){
    if(tPosX+MON_WIDTH<=0 ){
        monBack=true;
    }
    else{

        monBack=false;
    }
    if(monBack){
        tPosX=1280;
    }
}
void monsterGame::set_gMon(int trongLuc){
    g=trongLuc;
}
void monsterGame::move(int scrollingOffset,mainGame bossGame){
    tCollider.y=tPosY;
    tCollider.x=tPosX;
    if(collision==false){
        if(!checkCollision(bossGame.mCollider,tCollider))
       {
       tPosX -= monsterVel;
       tCollider.x=tPosX;
        }
        else
        {
        tPosX +=monsterVel;
        tCollider.x=tPosX;
        collision=true;
        }
        }
}
