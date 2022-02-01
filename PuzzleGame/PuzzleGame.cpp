
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

// You must include the command line parameters for your main function to be recognized by SDL
int main(int argc, char** args) {
    SDL_Window* win = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* bitmapTex = NULL;
    SDL_Surface* bitmapSurface = NULL;

    int width = 2560, height = 1440;
    SDL_bool loopShouldStop = SDL_FALSE;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();


    win = SDL_CreateWindow("Puzzle Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_FULLSCREEN);

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    bitmapSurface = IMG_Load("./img/Player.bmp");
    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    SDL_FreeSurface(bitmapSurface);


    
    TTF_Font* font = TTF_OpenFont("./fonts/arial.ttf", 48);

    SDL_Color foregroundColor = { 255, 255, 255 };
    SDL_Color backgroundColor = { 0, 0, 0, 0 };
    
    char txt[] = "Welcome to my game!";
    SDL_Surface* textSurface = TTF_RenderText_Shaded(font, txt , foregroundColor, backgroundColor);

    // Pass zero for width and height to draw the whole surface
    SDL_Rect textLocation = { 0, 0, 300, 40 };

    SDL_Texture *textTexture =  SDL_CreateTextureFromSurface(renderer, textSurface);
    
    SDL_Rect playerRect = { 0, 0, 128, 128 };

    if (!bitmapTex)
    {
        std::cout << "null\n";
    }

    const Uint8* state = SDL_GetKeyboardState(NULL);
   

    while (!loopShouldStop)
    {
        //DO EVENTS
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


        //DO BUTTON PRESSES
        if (state[SDL_SCANCODE_W]) {
            playerRect.y -= 5;
        }
        if (state[SDL_SCANCODE_A]) {
            playerRect.x -= 5;
        }
        if (state[SDL_SCANCODE_S]) {
            playerRect.y += 5;
        }
        if (state[SDL_SCANCODE_D]) {
            playerRect.x += 5;
        }

        //DO UPDATE


        //DO RENDER
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, textTexture, NULL, &textLocation);

        SDL_RenderCopy(renderer, bitmapTex, NULL, &playerRect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(bitmapTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}