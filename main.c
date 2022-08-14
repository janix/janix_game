
#include <SDL.h>
#include <stdio.h>
#include <glad/glad.h>

SDL_Window *window = NULL;


int init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    } else {
        printf("Your system is ready to go\n");
    }
    return 0;
}
int get_joystick()
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
    return 0;
}
int create_window()
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,24);


    window = SDL_CreateWindow(
        "Janix window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );
    SDL_GLContext context;
    context = SDL_GL_CreateContext(window);

    gladLoadGLLoader(SDL_GL_GetProcAddress);

    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    //main loop?
    return 0;
}



int main(int argc, char* argv[])
{
    
    init();
    get_joystick();
    create_window();
    int gameIsRunning = 1;
    while(gameIsRunning){
        glViewport(0,0,640,480);
        glClearColor(1.0f,0.0f,0.0f,1.0f);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        SDL_Event event;

        while(SDL_PollEvent(&event)){
            
            if(event.type == SDL_QUIT){
                gameIsRunning= 0;
            }
            if(event.type == SDL_MOUSEMOTION){
                printf("mouse has been moved\n");
            }
            if(event.type == SDL_CONTROLLER_BUTTON_B){
                printf("Button B has been pressed\n");
            }
        }
        SDL_GL_SwapWindow(window);
    }
    SDL_DestroyWindow(window);
    SDL_Delay(3000);
    SDL_Quit();

    return 0;
}
