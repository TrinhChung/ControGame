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
bool LTexture::loadFromRenderedText( std::string textureText, SDL_Color textColor ,TTF_Font* &gFont,SDL_Renderer* &gRenderer)
{
	free();

	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	if( textSurface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}
		SDL_FreeSurface( textSurface );
	}

	return mTexture != NULL;
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
	if( SDL_Init( SDL_INIT_VIDEO|SDL_INIT_AUDIO ) < 0 )
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
				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}
				if( Mix_OpenAudio( 4444, MIX_DEFAULT_FORMAT, 2, 1024 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
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
bool loadText(TTF_Font* &gFont,LTexture &gTextTexture,SDL_Renderer* &gRenderer,int sizeFont){
       bool success=true;
    gFont = TTF_OpenFont( "Bullpen3D.ttf" , sizeFont );
    if( gFont == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    else
    {
        SDL_Color textColor = { 0, 0, 0 };
        if(!gTextTexture.loadFromRenderedText( "GAME OVER", textColor,gFont,gRenderer) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }
    }
    return success;

}
bool loadMusic(Mix_Music* &gMusic,Mix_Chunk* &gScratch,Mix_Chunk* &gHigh,Mix_Chunk* &gMedium,Mix_Chunk* &gLow)
{
    bool success=true;
    gMusic = Mix_LoadMUS( "beat.wav" );
    if( gMusic == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    gScratch = Mix_LoadWAV( "point.wav" );
    if( gScratch == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    gHigh = Mix_LoadWAV( "gameover2.wav" );
    if( gHigh == NULL )
    {
        printf( "Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    gMedium = Mix_LoadWAV( "medium.wav" );
    if( gMedium == NULL )
    {
        printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    gLow = Mix_LoadWAV( "wing.wav" );
    if( gLow == NULL )
    {
        printf( "Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
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
void close(SDL_Renderer* &gRenderer,SDL_Window* &gWindow,Mix_Music* &gMusic,Mix_Chunk* &gScratch,Mix_Chunk* &gHigh,Mix_Chunk* &gMedium,Mix_Chunk* &gLow,TTF_Font* &gFont)
{
    TTF_CloseFont( gFont );
    gFont = NULL;


    Mix_FreeChunk( gScratch );
    Mix_FreeChunk( gHigh );
    Mix_FreeChunk( gMedium );
    Mix_FreeChunk( gLow );
    gScratch = NULL;
    gHigh = NULL;
    gMedium = NULL;
    gLow = NULL;

    Mix_FreeMusic( gMusic );
    gMusic = NULL;

	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	Mix_Quit();
}
void freeTexture(LTexture &gFooTexture)
{
    gFooTexture.free();
}
