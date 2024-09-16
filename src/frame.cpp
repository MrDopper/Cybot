#include "frame.h"

void Frame::draw(SDL_Texture *spriteSheet, float x, float y)
{
    //destination of where we want to draw this frame
    SDL_Rect dest; 
    dest.x = x - offSet.x; 
    dest.y = y - offSet.y;
    dest.w = clip.w;
    dest.h = clip.h; 

    renderTexture(spriteSheet, Globals::renderer, dest, &clip);  

}