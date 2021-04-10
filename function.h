#ifndef FUNCTION_H_
#define FUNCTION_H_
#include<SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include<SDL_ttf.h>
#include<stdio.h>
#include <string>
class LTexture
{
	public:
		LTexture();
		~LTexture();
		bool loadFromFile( std::string path,SDL_Renderer* &gRenderer);
		void free();
        Uint8 r = 255;
        Uint8 g = 255;
        Uint8 b = 255;
		void render( int x, int y,SDL_Renderer* &gRenderer,SDL_Rect* clip,double angle, SDL_Point* center, SDL_RendererFlip flip);
		int getWidth();
		int getHeight();
	private:
	     SDL_Texture* mTexture;
		int mWidth;
		int mHeight;
};
bool init(SDL_Window* &gWindow,int SCREEN_HEIGHT,int SCREEN_WIDTH,SDL_Renderer* &gRenderer);
bool loadMedia(LTexture &gFooTexture,SDL_Renderer* &gRenderer,std::string path);
void cutTexture(LTexture &gFooTexture,SDL_Rect gSpriteClips[],int WALKING_ANIMATION_FRAMES);
void close(SDL_Renderer* &gRenderer,SDL_Window* &gWindow);
void freeTexture(LTexture &gFooTexture);


#endif // FUNCTION_H_
