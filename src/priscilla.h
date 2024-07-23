#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "sdl_template.h"

typedef struct {
    int x, y, width, height;
    Color color;
} Button;

// Function to create a window
bool create_window(const char *title, int width, int height) {
    return init(title, width, height);
}

// Function to terminate the window
void terminate_window() {
    quit();
}

// Function to set the window background color
void window_background(Color color) {
    clear_screen(color);
}

// Main loop function
void main_loop() {
    while (active) {
        handle_events();
    }
}

// Function to create a button
Button create_button(const char *text, int width, int height, Color color) {
    Button button;
    button.x = 0; // Default position
    button.y = 0; // Default position
    button.width = width;
    button.height = height;
    button.color = color;
    // Initialize other button properties here, if necessary
    return button;
}

// Enumeration for button alignment
typedef enum {
    CENTERED,
    RIGHT,
    LEFT
} alignment;

// Function to align the button
void align_button(Button *button, alignment align) {
    if (align == CENTERED) {
        // align center
    } else if (align == RIGHT) {
        // align right
    } else if (align == LEFT) {
        // align left
    }
}

// Function to place the button at a specific position
void place_button(Button *button, int x, int y) {
    button->x = x;
    button->y = y;
}

