#ifndef FUNCTION_H_
#define FUNCTION_H_
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include"mainGame.h"
class LTexture
{
	public:
		LTexture();
		~LTexture();
		bool loadFromFile( std::string path,SDL_Renderer* &gRenderer);
		void free();
		void render( int x, int y,SDL_Renderer* &gRenderer);
		int getWidth();
		int getHeight();

	private:
		SDL_Texture* mTexture;
		int mWidth;
		int mHeight;
};
bool init(SDL_Window* &gWindow,int SCREEN_HEIGHT,int SCREEN_WIDTH,SDL_Renderer* &gRenderer);
bool loadMedia(LTexture &gFooTexture,LTexture &gBackgroundTexture,SDL_Renderer* &gRenderer);
void close(LTexture gFooTexture,LTexture gBackgroundTexture,SDL_Renderer* &gRenderer,SDL_Window* &gWindow);
#endif // FUNCTION_H_
