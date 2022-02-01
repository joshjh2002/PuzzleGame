
#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"


// You must include the command line parameters for your main function to be recognized by SDL
int main(int argc, char** args) {

    SDL_Window* win = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* bitmapTex = NULL;
    SDL_Surface* bitmapSurface = NULL;
    int posX = 100, posY = 100, width = 1280, height = 720;
    SDL_bool loopShouldStop = SDL_FALSE;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    win = SDL_CreateWindow("Puzzle Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_WINDOW_SHOWN);

    //bitmapSurface = SDL_LoadBMP("img/hello.bmp");
    //bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    //SDL_FreeSurface(bitmapSurface);

    TTF_Font* font = TTF_OpenFont("./arial.ttf", 12);

    if (!font)
    {
        std::cout << "null\n";
        return 0;
    }

    SDL_Color foregroundColor = { 255, 255, 255 };
    SDL_Color backgroundColor = { 0, 0, 255 };
    
    char txt[] = "This is my text.";
    SDL_Surface* textSurface = TTF_RenderText_Shaded(font, txt , foregroundColor, backgroundColor);

    // Pass zero for width and height to draw the whole surface
    SDL_Rect textLocation = { 100, 100, 0, 0 };

    while (!loopShouldStop)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                loopShouldStop = SDL_TRUE;
                break;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(bitmapTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}