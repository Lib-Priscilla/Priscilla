#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "sdl_template.h"

typedef struct {
    int x, y, width, height;
    Color color;
    void (*align)(struct Button *button, int alignment);
    void (*place)(struct Button *button, int x, int y);
} Button;

bool create_window(const char *title, int width, int height) {
    return init(title, width, height);
}

void terminate_window() {
    quit();
}

void window_background(Color color) {
    clear_screen(color);
}

void main_loop() {
    while (active) {
        handle_events();
    }
}

void draw_button(Button *button) {
    draw_rectangle(button->color, button->width, button->height, button->x, button->y, FILLED);
}

void align_button(Button *button, int alignment) {
    // Implement alignment logic, e.g., center, left, or right
    printf("Align button called with alignment: %d\n", alignment);
    // For example, if alignment is 1 (center), you might set button->x to center it on the screen
}

void place_button(Button *button, int x, int y) {
    button->x = x;
    button->y = y;
    printf("Place button called with coordinates: (%d, %d)\n", x, y);
}

Button create_button(int x, int y, int width, int height, Color color) {
    Button button;
    button.x = x;
    button.y = y;
    button.width = width;
    button.height = height;
    button.color = color;
    button.align = align_button;
    button.place = place_button;
    return button;
}

// Main function
int main(int argc, char *argv[]) {
    if (!create_window("Window Title", 800, 600)) {
        printf("Failed to create window\n");
        return -1;
    }

    // Create buttons
    Button button1 = create_button(50, 50, 100, 50, (Color){255, 0, 0, 255}); // Red button
    Button button2 = create_button(200, 50, 100, 50, (Color){0, 255, 0, 255}); // Green button

    // Use align and place methods
    button1.align(&button1, 1); // Example usage: 1 could mean center
    button2.place(&button2, 300, 200); // Example usage: place button at (300, 200)

    // Main loop
    main_loop();

    // Draw buttons (assuming you call this in your rendering function)
    draw_button(&button1);
    draw_button(&button2);

    terminate_window();
    return 0;
}
