#include<stdio.h>
#include<stdbool.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_image.h>
#include"sdl_template.h"


bool create_window(const char *title,int width, int height){
	init(title,width,height);
}

void terminate_window(){
	quit();
}
void window_background(Color color){
	clear_screen(color);
}
void main_loop(){
		while(active){
		handle_events();
	}
}
void button (Color color,int w,int h,int x,int y){
	draw_rectangle(color,w,h,x,y,FILLED);
}
