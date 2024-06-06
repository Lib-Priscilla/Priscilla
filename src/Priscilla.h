#ifndef  PRISCILLA_H
#define PRISCILLA_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf>
typedef struct{
	SDL_Window *sdl_window;
	SDL_Renderer*sdl_renderer;
	int width;
	int height;
	const char title*;
}window;

typedef struct {
    SDL_Rect rect;          // Position and size of the button
    SDL_Color color;        // Color of the button
    SDL_Texture *texture;   // Texture of the button (optional, for text or image)
    char *text;             // Text displayed on the button
    SDL_Renderer *renderer; // Renderer for rendering the button
    void (*onClick)(void);  // Callback function for button click event
} Button;

// WINDOW MANAGEMENT(INIT AND QUIT)
int window_init(Window *window, const char *title, int width, int height); // initialize window
void quit(Window *window); //quit at the end of every program


// BUTTON
void create_button(char text,int width, int height,int x,int y){
	
}

#endif // PRISCILLA_H
