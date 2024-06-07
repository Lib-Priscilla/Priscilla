#include "Priscilla.h"
int main(int argc, char *argv[]) {
    Window window;
    if (window_init(&window, "My GUI Library", 800, 600) < 0) {
        return -1;
    }

    TTF_Font *font = TTF_OpenFont("path/to/font.ttf", 24);
    if (!font) {
        printf("Failed to load font. TTF Error: %s\n", TTF_GetError());
        quit(&window, NULL, 0);
        return -1;
    }

    Button buttons[2];
    create_button(&buttons[0], "Button 1", font, 24);
    create_button(&buttons[1], "Button 2", font, 24);

    SDL_Event event;
    while (1) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit(&window, buttons, 2);
                return 0;
            }
            handle_button_event(&event, &buttons[0]);
            handle_button_event(&event, &buttons[1]);
        }

        SDL_SetRenderDrawColor(window.sdl_renderer, 255, 255, 255, 255);
        SDL_RenderClear(window.sdl_renderer);

        draw_button(&window, &buttons[0], 150, 50, 100, 100, (SDL_Color){255, 0, 0, 255}, (SDL_Color){255, 255, 255, 255});
        draw_button(&window, &buttons[1], 150, 50, 100, 200, (SDL_Color){0, 255, 0, 255}, (SDL_Color){255, 255, 255, 255});

        SDL_RenderPresent(window.sdl_renderer);

        SDL_Delay(16); // ~60 FPS
    }

    TTF_CloseFont(font);
    quit(&window, buttons, 2);
    return 0;
}
