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
void quit(Window *window, Button *buttons, int buttonCount) {
    for (int i = 0; i < buttonCount; ++i) {
        free(buttons[i].text);
    }
    if (window->sdl_renderer) {
        SDL_DestroyRenderer(window->sdl_renderer);
    }
    if (window->sdl_window) {
        SDL_DestroyWindow(window->sdl_window);
    }
    TTF_Quit();
    SDL_Quit();
}


// BUTTON
void create_button(Button *button, const char *text,TTF_Font *font, int fontSize ){
	button->text=strdup(text);
	button->font=font;
	button->fontSize=fontSize;
}
void draw_button(Window *window, Button *button, int width, int height, int x, int y, SDL_Color buttonColor, SDL_Color textColor) {
    button->rect = (SDL_Rect){x, y, width, height};
    button->buttonColor = buttonColor;
    button->textColor = textColor;

    // Set button color and render button rectangle
    SDL_SetRenderDrawColor(window->sdl_renderer, buttonColor.r, buttonColor.g, buttonColor.b, buttonColor.a);
    SDL_RenderFillRect(window->sdl_renderer, &button->rect);

    // Render button text
    SDL_Surface *textSurface = TTF_RenderText_Solid(button->font, button->text, textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(window->sdl_renderer, textSurface);
    SDL_Rect textRect = {x + (width - textSurface->w) / 2, y + (height - textSurface->h) / 2, textSurface->w, textSurface->h};
    SDL_RenderCopy(window->sdl_renderer, textTexture, NULL, &textRect);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}
