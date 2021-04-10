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
      void render(LTexture &gFooTexture,SDL_Renderer* &gRenderer,SDL_Rect* clip);
      bool move(int scrollingOffset,mainGame bossGame);
      void setWidth_Height(int width,int height);
      void setPosX(int PosX);
      void setPosY(SDL_Rect wall,int val_Y);
      int getPosX();
private:
        int tPosX, tPosY;
        SDL_Rect tCollider;

};
#endif // MONSTERGAME_H_
