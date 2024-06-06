#include "Priscilla.h"
#include <stdio.h>

// INITIALIZATION FUNCTION
int window_init(Window *window, const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL INIT FAILED. SDL ERROR: %s\n", SDL_GetError());
        return -1;
    }
    // Create window
    window->sdl_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window->sdl_window == NULL) {
        printf("COULD NOT CREATE WINDOW. SDL ERROR: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }
    // Create renderer
    window->sdl_renderer = SDL_CreateRenderer(window->sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (window->sdl_renderer == NULL) {
        printf("SDL RENDERER FAILED. SDL ERROR: %s\n", SDL_GetError());
        SDL_DestroyWindow(window->sdl_window);
        SDL_Quit();
        return -1;
    }

    window->width = width;
    window->height = height;
    window->title = title;

    return 0;
}

// QUIT FUNCTION
void quit(Window *window) {
    if (window->sdl_renderer) {
        SDL_DestroyRenderer(window->sdl_renderer);
    }
    if (window->sdl_window) {
        SDL_DestroyWindow(window->sdl_window);
    }
    SDL_Quit();
}

// BUTTON
void create_button(char text,int width, int height,int x,int y){
	
}
