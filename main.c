#include <SDL2/SDL.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
    SDL_Window *window = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Video initialization Error %s\n", SDL_GetError());
    }
    else 
    {
        window = SDL_CreateWindow("Janix Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf("Window creation error %s\n", SDL_GetError());
        }
        else
        {
            SDL_UpdateWindowSurface(window);
            SDL_Delay(6000);
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}