#ifndef  PRISCILLA_H
#define PRISCILLA_H
// LIBRARIES USED
#include<SDL2/SDL.h>
// #include<SDL2/SDL_ttf>


typedef struct{
	SDL_Window *sdl_window;
	SDL_Renderer*sdl_renderer;
	int width;
	int height;
	const char title*;
}window;

typedef struct {
    char *text;
    TTF_Font *font;
    int fontSize;
    SDL_Rect rect;
    SDL_Color buttonColor;
    SDL_Color textColor;
} Button;

// WINDOW MANAGEMENT(INIT AND QUIT)
int window_init(Window *window, const char *title, int width, int height); // initialize window
void quit(Window *window); //quit at the end of every program


// BUTTON
void create_button(char text,int width, int height,int x,int y);
void draw_button(Window *window, Button *button, int width, int height,int x,int y,SDL_Color buttonColor, SDL_Color textColor);

#endif // PRISCILLA_H
