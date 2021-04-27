#include<ctime>
#include<stdlib.h>
#include<sstream>
#include<fstream>
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

LTexture gFooTexture;
LTexture gBackgroundTexture;
LTexture gFooTextureDown;
LTexture gMonster1;
LTexture gMonster2;
LTexture gMonster3;
LTexture gTextTexture;
LTexture gPromptTextTexture;
LTexture gMonster4;

LTexture gLogo;

monsterGame monster1,monster2,monster3,monster4;
mainGame bossGame;

const int SCREEN_WIDTH = 969;
const int SCREEN_HEIGHT =532;

const int MONSTER_WIDTH_1=130;
const int MONSTER_HEIGHT_1=150;

const int MONSTER_HEIGHT_2=140;
const int MONSTER_WIDTH_2=150;

const int MONSTER_HEIGHT_3=140;
const int MONSTER_WIDTH_3=150;

const int MONSTER_HEIGHT_4=158;
const int MONSTER_WIDTH_4=99;

const int MAIN_WIDTH=81;
const int MAIN_HEIGHT=100;

const int MAIN_WIDTH_DOWN=76;
const int MAIN_HEIGHT_DOWN=76;

Mix_Music *gMusic = NULL;
Mix_Chunk *gScratch = NULL;
Mix_Chunk *gHigh = NULL;
Mix_Chunk *gMedium = NULL;
Mix_Chunk *gLow = NULL;

TTF_Font *gFont = NULL;

const std::string mainG="manwalk5.png";
const std::string background="ground.png";

const int WALKING_ANIMATION_FRAMES = 10;
SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES];
SDL_Rect gSpriteClips1[7];
SDL_Rect gSpriteClips2[WALKING_ANIMATION_FRAMES];
SDL_Rect gSpriteClips3[WALKING_ANIMATION_FRAMES];
SDL_Rect gSpriteClips4[6];
SDL_Rect* clip=NULL;

