#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include"function.h"
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 680;
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
LTexture gFooTexture;
LTexture gBackgroundTexture;
int main( int argc, char* args[] )
{
	if( !init(gWindow,SCREEN_HEIGHT,SCREEN_WIDTH,gRenderer) )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia(gFooTexture,gBackgroundTexture,gRenderer) )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			bool quit = false;
			SDL_Event e;
			while( !quit )
			{
				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}
				SDL_Rect stretchRect;
				stretchRect.x = 0;
				stretchRect.y = 0;
				stretchRect.w = SCREEN_WIDTH;
				stretchRect.h = SCREEN_HEIGHT;
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
				gBackgroundTexture.render( 0, 0 ,gRenderer);
				gFooTexture.render( 20, 260 ,gRenderer);
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	close(gFooTexture,gBackgroundTexture,gRenderer,gWindow);

	return 0;
}
