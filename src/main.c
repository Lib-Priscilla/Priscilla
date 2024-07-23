#include<stdio.h>
#include<stdbool.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_image.h>
#include"priscilla.h"

int main( ) {
    create_window("Window Title", 800, 600)

	Button myButton = create_button("Click Me", 200, 50, buttonColor);
    place_button(&myButton, 100, 100);
    align_button(&myButton, CENTERED);

    // Main loop
    main_loop();
    terminate_window();
    return 0;
}
	return 0;
}
