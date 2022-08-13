
#include <SDL.h>
#include <stdio.h>

void init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    }
}
void get_joystick()
{
    SDL_GameController *ctrl;
    SDL_Joystick *joy;
    int i;

    for(i = 0; i < SDL_NumJoysticks(); ++i) {
        if (SDL_IsGameController(i)) {
            printf("Index \'%i\' is a compatible controller, named \'%s\'\n", i, SDL_GameControllerNameForIndex(i));
            ctrl = SDL_GameControllerOpen(i);
            joy = SDL_GameControllerGetJoystick(ctrl);
        } else {
            printf("Index \'%i\' is not a compatible controller.\n", i);
        }
    }
}


int main(int argc, char* argv[])
{
    init();
    get_joystick();
    SDL_Quit();

    return 0;
}
