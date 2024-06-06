#ifndef BUTTON_H
#define BUTTON_H
typedef struct {
    SDL_Rect rect;          // Position and size of the button
    SDL_Color color;        // Color of the button
    SDL_Texture *texture;   // Texture of the button (optional, for text or image)
    char *text;             // Text displayed on the button
    SDL_Renderer *renderer; // Renderer for rendering the button
    void (*onClick)(void);  // Callback function for button click event
} Button;


#endif BUTTON_H
