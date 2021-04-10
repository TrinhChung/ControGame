#include"function.h"
LTexture::LTexture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	free();
}
bool LTexture::loadFromFile( std::string path,SDL_Renderer* &gRenderer)
{
	free();

	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "error loadFromTure", path.c_str(), IMG_GetError() );
	}
	else
	{
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 64, 54, 34 ) );
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "error loadFromTure", path.c_str(), SDL_GetError() );
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		SDL_FreeSurface( loadedSurface );
	}
	mTexture = newTexture;
	return mTexture != NULL;
}
void LTexture::free()
{
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}
void LTexture::render( int x, int y,SDL_Renderer* &gRenderer,SDL_Rect* clip,double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad ,angle,center,flip);
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}
bool init(SDL_Window* &gWindow,int SCREEN_HEIGHT,int SCREEN_WIDTH,SDL_Renderer* &gRenderer)
{
	bool success = true;
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			 gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
			else
			{
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}
bool loadMedia(LTexture &gFooTexture,SDL_Renderer* &gRenderer,std::string path)
{
	bool success = true;
	if( !gFooTexture.loadFromFile( path,gRenderer))
	{
		printf( "Failed to load media texture image!\n" );
		success = false;
	}
	return success;
}
void cutTexture(LTexture &gFooTexture,SDL_Rect gSpriteClips[],int WALKING_ANIMATION_FRAMES)
{

    for(int i=0;i<WALKING_ANIMATION_FRAMES;i++)
    {
        gSpriteClips[ i ].x =  gFooTexture.getWidth()*i/WALKING_ANIMATION_FRAMES;
        gSpriteClips[ i ].y =   0;
        gSpriteClips[ i ].w = gFooTexture.getWidth()/WALKING_ANIMATION_FRAMES;
        gSpriteClips[ i ].h = gFooTexture.getHeight();
    }
}
void close(SDL_Renderer* &gRenderer,SDL_Window* &gWindow)
{
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
void freeTexture(LTexture &gFooTexture)
{
    gFooTexture.free();
}
