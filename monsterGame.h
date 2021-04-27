#ifndef  MONSTERGAME_H_
#define MONSTERGAME_H_
#include"mainGame.h"
class monsterGame {
public:
     SDL_RendererFlip flipType = SDL_FLIP_HORIZONTAL;
       int MON_WIDTH;
       int MON_HEIGHT;
       monsterGame();
      ~monsterGame();
      int monsterVel;
      void render(LTexture &gFooTexture,SDL_Renderer* &gRenderer,SDL_Rect* clip);
      void move(int scrollingOffset,mainGame bossGame);
      void setWidth_Height(int width,int height);
      bool collision;
      bool monBack;
      int g;
      void set_gMon(int trongLuc);
      void returnMon();
      void setVel(int vel);

      void setPosX(int PosX);
      void setPosY(SDL_Rect wall,int val_Y);
      int getPosX();
private:
        int tPosX, tPosY;
        SDL_Rect tCollider;

};
#endif // MONSTERGAME_H_
