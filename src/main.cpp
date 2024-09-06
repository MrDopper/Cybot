#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <cleanup.h>
#include <iostream>
#include <SDL2_mixer/SDL_mixer.h>
#include "res_path.h"
#include "drawing_functions.h"

using std::cout, std::endl, std::string;

int main(int argc, char *argv[])
{
    // Set up SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "The SDL library hasn't set up" << endl;
        return 1;
    }
    // Set up Window
    SDL_Window *window = SDL_CreateWindow("Cybot_game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 320, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr)
    {
        SDL_Quit();
        cout << "There is an error with window" << endl;
        return 1;
    }
    // Set up Renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        SDL_Quit();
        cout << "There is an error with renderer" << endl;
        return 1;
    }
    // THis is the size to draw thing at
    SDL_RenderSetLogicalSize(renderer, 640, 320);

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        cout << "The image is not initialized" << endl;
        return 1;
    }
    // Initialize the text form
    if (TTF_Init() != 0)
    {
        SDL_Quit();
        cout << "sdl tff is not intitalized" << endl;
        return 1;
    }
    // Initialized the sounds
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    {
        SDL_Quit();
        cout << "SDL mixer doesn't respond" << endl;
        return 1;
    }
    // load up a texture to draw
    string resPath = getResourcePath();
    SDL_Texture *texture = loadTexture(resPath + "map.png", renderer);

    // Run Game for 5000 ticks
    while (SDL_GetTicks() < 5000)
    {
        // CLean the screen
        SDL_RenderClear(renderer);
        // draw what we want on the screen
        renderTexture(texture, renderer, 0, 0);
        // show the image has been rendering
        SDL_RenderPresent(renderer);
    }
    cleanup(renderer);
    cleanup(window);
    cleanup(texture);

    SDL_Quit();
    return 0;
}