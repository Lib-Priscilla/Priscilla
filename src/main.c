#include<stdio.h>
#include<stdbool.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_image.h>
#include"priscilla.h"

int main (){
	  
    create_window("GUI",720,360);
	window_background(WHITE);
	button(GRAY,50,50,40,50);
        // Present the rendered frame
       present();
       main_loop();
	terminate_window();
	return 0;
}
