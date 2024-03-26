/*
* Programmer: Carlos completed: March 26, 2024
*
* Instructor: Book
*
* Description: Draw diagrams from the figure 3.9 in the book

*Dependencies: 
*    - SDL2: libsdl2-dev
*    - SDL_ttf: libsdl2-ttf-dev (if using SDL_ttf)
* 
*Parameters:
*	-Wall -Wextra -std=c99 -lSDL2 -lSDL2_ttf
*/

#include <stdio.h>
#include <SDL2/SDL.h>

int main() 
{
    int bigX;
    int bigY;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Get the maximum width and height of the screen
    SDL_DisplayMode displayMode;
    if (SDL_GetDesktopDisplayMode(0, &displayMode) != 0) {
        printf("Error getting desktop display mode: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    bigX = displayMode.w;
    bigY = displayMode.h;

    // Create a full screen window
    SDL_Window *window = SDL_CreateWindow("Full screen window - press a key to close",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          bigX, bigY,
                                          SDL_WINDOW_FULLSCREEN);
    if (window == NULL) {
        printf("Error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Draw intersecting lines
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white color
    SDL_RenderDrawLine(renderer, 0, 0, bigX, bigY); // white line
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // blue color
    SDL_RenderDrawLine(renderer, bigX, 0, 0, bigY); // blue line

    // Present on the screen
    SDL_RenderPresent(renderer);

    // Display window size in the console
    printf("Window size is %d X %d\n", bigX, bigY);

    // Wait until the user presses a key
    SDL_Event event;
    while (SDL_WaitEvent(&event) && event.type != SDL_QUIT && event.type != SDL_KEYDOWN) {}

    // Clean up resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
