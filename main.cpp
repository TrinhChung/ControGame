#include"monsterGame.h"
#include"Timer.h"
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
LTexture gFooTexture;
LTexture gBackgroundTexture;
monsterGame monster1,monster2;
mainGame bossGame;
LTexture gMonster1;
LTexture gMonster2;
LTimer timer;
const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 960;
const int SCREEN_WIDTH = 969;
const int SCREEN_HEIGHT =680;
const int MONSTER_WIDTH_1=126;
const int MONSTER_HEIGHT_1=100;
const int MONSTER_HEIGHT_2=93;
const int MONSTER_WIDTH_2=96;
const std::string mainG="manwalk2.png";
const std::string background="background4.png";
const int WALKING_ANIMATION_FRAMES = 10;
SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES];
SDL_Rect gSpriteClips1[6];
SDL_Rect gSpriteClips2[WALKING_ANIMATION_FRAMES];

SDL_Rect* clip=NULL;

int main( int argc, char* args[] )
{

	if( !init(gWindow,SCREEN_HEIGHT,SCREEN_WIDTH,gRenderer) )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		if( !(loadMedia(gFooTexture,gRenderer,mainG)&&loadMedia(gBackgroundTexture,gRenderer,background)
        && loadMedia(gMonster1,gRenderer,"flydino1.png")&&loadMedia(gMonster2,gRenderer,"mano.png")))
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			bool quit = false;
			double fame=0;
			double fame1=0;
			SDL_Event e;
            SDL_Rect wall;
            wall.x = 0;
            wall.y = 445;
            wall.w = SCREEN_WIDTH;
            wall.h = 200;
            int scrollingOffset = 0;
            monster1.setPosX(0);
            monster2.setPosX(1280);
            monster1.setWidth_Height(MONSTER_WIDTH_1,MONSTER_HEIGHT_1);
            monster2.setWidth_Height(MONSTER_WIDTH_2,MONSTER_HEIGHT_2);
            monster1.setPosY(wall,100);
            monster2.setPosY(wall,0);
            monsterGame();
			while( !quit )
			{
				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					else{
                        mainGame();
                        bossGame.handleEvent(e,WALKING_ANIMATION_FRAMES,wall);
					}

				}
                std::cout<<bossGame.onGround(wall)<<std::endl;
                 bossGame.move(wall);
                if(monster1.move(scrollingOffset,bossGame) && monster2.move(scrollingOffset,bossGame)){
                    scrollingOffset-=2;
                    fame+=0.1;
                    fame1+=0.05;
                  if(!bossGame.onGround(wall))
                  {
                    fame=7;
                  }
                  if(fame1>6)
                  {
                    fame1=(int)fame1%6;
                  }
                  if(fame>10)
                  {
                    fame=(int)fame%10;
                  }
                  }
                  if( scrollingOffset < -gBackgroundTexture.getWidth())
                  {
                    scrollingOffset = 0;
                  }
                 if( monster1.move(scrollingOffset,bossGame)==false||monster2.move(scrollingOffset,bossGame)==false)
                {
                    scrollingOffset = 0;
                    fame=0;
                }
                cutTexture(gFooTexture,gSpriteClips,WALKING_ANIMATION_FRAMES);
                cutTexture(gMonster1,gSpriteClips1,6);
                cutTexture(gMonster2,gSpriteClips2,WALKING_ANIMATION_FRAMES);

				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

                SDL_Rect* currentClip = &gSpriteClips[(int)fame];
                SDL_Rect* currentClip1=&gSpriteClips1[(int)fame1];
                SDL_Rect* currentClip2=&gSpriteClips2[(int)fame1];
                gBackgroundTexture.render(scrollingOffset,0,gRenderer,NULL,0,NULL,SDL_FLIP_NONE);
                gBackgroundTexture.render(scrollingOffset+gBackgroundTexture.getWidth(),0,gRenderer,NULL,0,NULL,SDL_FLIP_NONE);

                bossGame.render(gFooTexture,gRenderer,currentClip);
                monster1.render(gMonster1,gRenderer,currentClip1);
                monster2.render(gMonster2,gRenderer,currentClip2);
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	freeTexture(gFooTexture);
	freeTexture(gBackgroundTexture);
    freeTexture(gMonster1);
    freeTexture(gMonster2);
	close(gRenderer,gWindow);
	return 0;
}

