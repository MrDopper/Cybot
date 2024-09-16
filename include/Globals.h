#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL2/SDL.h>
#include <cstring>
#include <iostream>
#include <randomNumber.h>

class Globals
{
public:
    static const float PI;
    static bool debugging;
    static int ScreenWidth, ScreenHeight, ScreenScale;
    static SDL_Renderer *renderer;
};

#endif
