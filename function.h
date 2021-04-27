#ifndef FUNCTION_H_
#define FUNCTION_H_
#include<SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include<SDL_ttf.h>
#include<stdio.h>
#include <SDL_mixer.h>
#include <string>
class LTexture
{
	public:
		LTexture();
		~LTexture();
		bool loadFromFile( std::string path,SDL_Renderer* &gRenderer);
		void free();
        bool loadFromRenderedText( std::string textureText, SDL_Color textColor,TTF_Font* &gFont,SDL_Renderer* &gRenderer);
		void render( int x, int y,SDL_Renderer* &gRenderer,SDL_Rect* clip,double angle, SDL_Point* center, SDL_RendererFlip flip);
		int getWidth();
		int getHeight();
	private:
	     SDL_Texture* mTexture;
		int mWidth;
		int mHeight;
};
bool loadText(TTF_Font* &gFont,LTexture &gTextTexture,SDL_Renderer* &gRenderer,int sizeFont);
bool init(SDL_Window* &gWindow,int SCREEN_HEIGHT,int SCREEN_WIDTH,SDL_Renderer* &gRenderer);
bool loadMedia(LTexture &gFooTexture,SDL_Renderer* &gRenderer,std::string path);
void cutTexture(LTexture &gFooTexture,SDL_Rect gSpriteClips[],int WALKING_ANIMATION_FRAMES);
void close(SDL_Renderer* &gRenderer,SDL_Window* &gWindow,Mix_Music* &gMusic,Mix_Chunk* &gScratch,Mix_Chunk* &gHigh,Mix_Chunk* &gMedium,Mix_Chunk* &gLow,TTF_Font* &gFont);
void freeTexture(LTexture &gFooTexture);
bool loadMusic(Mix_Music* &gMusic,Mix_Chunk* &gScratch,Mix_Chunk* &gHigh,Mix_Chunk* &gMedium,Mix_Chunk* &gLow);

#endif // FUNCTION_H_
