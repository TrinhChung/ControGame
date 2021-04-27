#include"monsterGame.h"
#include"bien.h"
int main( int argc, char* args[] )
{
    std::ifstream fi("score.txt",std::ios::in);
    srand(time(NULL));
	if( !init(gWindow,SCREEN_HEIGHT,SCREEN_WIDTH,gRenderer) )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		if( !(loadMedia(gFooTexture,gRenderer,mainG)&&loadMedia(gBackgroundTexture,gRenderer,background)&& loadText(gFont,gTextTexture,gRenderer,28) && loadMedia(gMonster4,gRenderer,"Cactus.png")
        && loadMedia(gMonster1,gRenderer,"dinofly2.png")&&loadMedia(gMonster2,gRenderer,"manon2.png")&& loadMusic(gMusic,gScratch,gHigh,gMedium,gLow)
        && loadMedia(gFooTextureDown,gRenderer,"maindown.png")&&loadMedia(gMonster3,gRenderer,"dino2.png")&& loadMedia(gLogo,gRenderer,"LogoGame.png")))
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			bool quit = false;
            bool start=false;
            bool over=true;

            int maxScore;
            int rand_x;
            int scrollingOffset = 0;
            int speed=0;

			double fame=0;
			double fame1=0;
			double fame2=0;

            Uint32 score=0;
            Uint32 timeAo=0;

			SDL_Event e;
            SDL_Rect wall;
            wall.x = 0;
            wall.y = 445;
            wall.w = SCREEN_WIDTH;
            wall.h = 0;
            SDL_Color textColor = { 0, 0, 0, 255 };
            std::stringstream timeText;

            monster3.setWidth_Height(MONSTER_WIDTH_3,MONSTER_HEIGHT_3);
            monster1.setWidth_Height(MONSTER_WIDTH_1,MONSTER_HEIGHT_1);
            monster2.setWidth_Height(MONSTER_WIDTH_2,MONSTER_HEIGHT_2);
            monster4.setWidth_Height(MONSTER_WIDTH_4,MONSTER_HEIGHT_4);
            monster1.setPosY(wall,80);
            monster2.setPosY(wall,0);
            monster3.setPosY(wall,0);
            monster4.setPosY(wall,0);

			while( !quit )
			{
				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					else{

                        if(start){
                            bossGame.handleEvent(e,WALKING_ANIMATION_FRAMES,wall,gLow);
                        }

                        if( e.type == SDL_KEYDOWN)
                         {
                        if( e.key.keysym.sym== SDLK_RETURN && start==false)
                        {
                         start=true;
                         monster1.setPosX(1280);
                         timeAo=SDL_GetTicks();
                        }

                        if(over==false)
                        {
                         if( e.type == SDL_KEYDOWN)
                         {
                         if( e.key.keysym.sym== SDLK_RETURN )
                         {
                                 monster1.setPosX(-500);
                                 monster2.setPosX(-500);
                                 monster3.setPosX(-500);
                                 monster4.setPosX(-500);
                                 monster2.setPosX(1280);
                                 monster1.collision=false;
                                 monster2.collision=false;
                                 monster3.collision=false;
                                 monster4.collision=false;
                                 score=0;
                                 timeAo=SDL_GetTicks();
                                 over=true;
                         }
                         }
                        }
                      }
					}
				}
                int g=score/15+3;
                int randMon;

                fi >>maxScore;
				Uint32 startTime=0;

				if(start)
                {
                    startTime= SDL_GetTicks()-timeAo;
				}
				Uint32 Time;
				speed=startTime/10000;
				rand_x=rand()%20;
                scrollingOffset-=3+speed;

                fame +=0.1+speed/200000;
                fame1+=0.075+speed/200000;

                if( monster4.getPosX()-bossGame.getPosX()<=250 && monster4.getPosX()-bossGame.getPosX()>0)
                {
                fame2+=0.3+speed/200000;
                }

               if(monster1.getPosX()+MONSTER_WIDTH_1<=4+speed+600&&monster1.getPosX()+MONSTER_WIDTH_1>600)
                {
                    randMon=rand()%3;
                    if(randMon==0){monster2.returnMon();}
                    if(randMon==1){monster3.returnMon();}
                    if(randMon==2){monster4.returnMon();}
                    std::cout<<randMon<<" ";
                }
                 if(monster2.getPosX()+MONSTER_WIDTH_2<=4+speed+500&&monster2.getPosX()+MONSTER_WIDTH_2>500)
                 {
                     randMon=rand()%3;
                    if(randMon==0)
                    {
                        monster1.setPosY(wall,80+rand_x);
                        monster1.returnMon();
                    }
                    if(randMon==1){monster3.returnMon();}
                    if(randMon==2){monster4.returnMon();}
                     std::cout<<randMon<<" ";
                }
                 if(monster3.getPosX()+MONSTER_WIDTH_3<=4+speed+300&&monster3.getPosX()+MONSTER_WIDTH_3>300)
                 {
                    randMon=rand()%3;
                    if(randMon==0){
                            monster1.setPosY(wall,rand_x);
                            monster1.returnMon();}
                    if(randMon==1){monster2.returnMon();}
                    if(randMon==2){monster4.returnMon();}
                     std::cout<<randMon<<" ";
                }
                if(monster4.getPosX()+MONSTER_WIDTH_4<=3+speed&&monster4.getPosX()+MONSTER_WIDTH_4>0)
                {
                     randMon=rand()%3;
                    if(randMon==0){
                            monster1.setPosY(wall,rand_x);
                            monster1.returnMon();}
                    if(randMon==1){monster2.returnMon();}
                    if(randMon==2){monster3.returnMon();}
                    fame2=0;
                     std::cout<<randMon<<" ";
                }
                if(Time%10000>0 && Time%10000<100)
                {
                      Mix_PlayChannel( -1, gScratch, 0 );
                }

                if(monster1.collision==false && monster2.collision==false
                && monster3.collision==false &&  monster4.collision==false)
                {
                    if(!bossGame.bow)
                    {
                        bossGame.setWidth_Height(MAIN_WIDTH,MAIN_HEIGHT);
                    }
                    if(bossGame.bow)
                    {
                        bossGame.setWidth_Height(MAIN_WIDTH_DOWN,MAIN_HEIGHT_DOWN);
                    }
                    Time=startTime;
                    bossGame.move(wall,g);
                    monster1.move(scrollingOffset,bossGame);
                    monster2.move(scrollingOffset,bossGame);
                    monster3.move(scrollingOffset,bossGame);
                    monster4.move(scrollingOffset,bossGame);

                    monster1.setVel(speed+4);
                    monster2.setVel(speed+4);
                    monster3.setVel(speed+4);
                    monster4.setVel(speed+3);

                    if( (bossGame.getPosX()>=monster1.getPosX()&&bossGame.getPosX()<monster1.getPosX()+speed+4)
                       ||(bossGame.getPosX()>=monster2.getPosX()&&bossGame.getPosX()<monster2.getPosX()+speed+4)
                       ||(bossGame.getPosX()>=monster3.getPosX()&&bossGame.getPosX()<monster3.getPosX()+speed+4)
                       ||(bossGame.getPosX()>=monster4.getPosX()&&bossGame.getPosX()<monster4.getPosX()+speed+3))
                    {
                        score++;
                    }

                  if(!bossGame.onGround(wall))
                  {
                    fame=6;
                  }
                  if(fame1>6)
                  {
                    fame1=(int)fame1%6;
                  }
                  if(fame2>=6)
                  {
                    fame2=5;
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

                 if( (monster1.collision || monster2.collision || monster3.collision || monster4.collision)==true)
                {
                    scrollingOffset = 0;
                    SDL_GetTicks();
                    if(over){
                    Mix_PlayChannel( -1, gHigh, 0 );
                    over=false;

                    }
                    fame=0;
                    fame1=0;

                    bossGame.setPosY(wall.y-MAIN_HEIGHT);
                    if(score > maxScore){
                        maxScore=score;
                        std::ofstream fo("score.txt",std::ios::out);
                        fo <<score;
                        fo.close();
                    }
                }
                timeText.str( "" );
                timeText <<"SCORE: "<<score<<"          "<<"MAXSCORE: "<<maxScore<<"             "<< "TIME: " <<Time;

                if( !gPromptTextTexture.loadFromRenderedText( timeText.str().c_str(), textColor,gFont,gRenderer) )
                {
                    printf( "Unable to render time texture!\n" );
                }

                cutTexture(gFooTexture,gSpriteClips,WALKING_ANIMATION_FRAMES);
                cutTexture(gMonster1,gSpriteClips1,7);
                cutTexture(gMonster2,gSpriteClips2,8);
                cutTexture(gMonster3,gSpriteClips3,WALKING_ANIMATION_FRAMES);
                cutTexture(gMonster4,gSpriteClips4,6);

				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

                SDL_Rect* currentClip =&gSpriteClips[(int)fame];
                SDL_Rect* currentClip1=&gSpriteClips1[(int)fame1];
                SDL_Rect* currentClip2=&gSpriteClips2[(int)fame1];
                SDL_Rect* currentClip3=&gSpriteClips3[(int)fame1];
                SDL_Rect* currentClip4=&gSpriteClips4[(int)fame2];


                gBackgroundTexture.render(scrollingOffset,0,gRenderer,NULL,0,NULL,SDL_FLIP_NONE);
                gBackgroundTexture.render(scrollingOffset+gBackgroundTexture.getWidth(),0,gRenderer,NULL,0,NULL,SDL_FLIP_NONE);

                if(!start){
                    gLogo.render(0,20  ,gRenderer,NULL,0,NULL,SDL_FLIP_NONE);
                }

                if(!bossGame.bow){
                        bossGame.render(gFooTexture,gRenderer,currentClip);
                }
                if(bossGame.bow){
                        bossGame.render(gFooTextureDown,gRenderer,NULL);
                }

                monster1.render(gMonster1,gRenderer,currentClip1);
                monster2.render(gMonster2,gRenderer,currentClip2);
                monster3.render(gMonster3,gRenderer,currentClip3);
                monster4.render(gMonster4,gRenderer,currentClip4);

                if(!over)gTextTexture.render(330,300,gRenderer,NULL,0,NULL,SDL_FLIP_NONE);
                gPromptTextTexture.render( 10, 0,gRenderer,NULL,0,NULL,SDL_FLIP_NONE );
				SDL_RenderPresent( gRenderer );
			}
		}
	}
    fi.close();
	freeTexture(gFooTexture);
	freeTexture(gFooTextureDown);
	freeTexture(gBackgroundTexture);
    freeTexture(gMonster1);
    freeTexture(gMonster2);
    freeTexture(gMonster3);
    freeTexture(gMonster4);
    freeTexture(gTextTexture);
    freeTexture(gPromptTextTexture);
    freeTexture(gLogo);
	close(gRenderer,gWindow,gMusic,gScratch,gHigh,gMedium,gLow,gFont);
	return 0;
}

