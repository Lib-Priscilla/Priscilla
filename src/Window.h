#ifndef  WINDOW_H
#define WINDOW_H

#include<SDL2/SDL.h>

typedef struct{
	SDL_Window *sdl_window;
	SDL_Renderer*sdl_renderer;
	int width;
	int height;
	const char title*;
	int running;
}window;

int window_init(Window *window, const char *title, int width, int height); // initialize window
void quit(Window *window); //quit at the end of every program
void update(Window *window); // present / update the screen
void loop (Window*window,void(*update)(window*),void(*render)(window*)); // to loop the main window

#endif // WINDOW_H
