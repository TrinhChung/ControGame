#ifndef LOADTEXTURE_H_
#define LOADTEXTURE_H_
#include<SDL_ttf.h>
#include<string>
class Texture{
public:
     Texture();
     ~Texture();
     bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
     void loadTexure();
     void free();

};
#endif // LOADTEXTURE_H_
