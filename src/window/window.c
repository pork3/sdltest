#include <stdlib.h>
#include <SDL2/SDL.h>

#include "window.h"
#include "../settings.h"
#include "../errorhandle/erros.h"

typedef struct windowdata{
	int width;
	int height;
	/*SDL define datatype for the window and surface to draw on*/
	SDL_Surface* ssurface;
	SDL_Window* window;
} windowdata;

/*fucntion to free resources from sdl*/
static void destroy_window_s(const Window_t* window){
	windowdata* wd = (windowdata*) window->data;
	/*free the scree surface*/
	SDL_FreeSurface( wd->ssurface);
	SDL_DestroyWindow( wd->window);
	/*set pointers to null*/
	wd->window =NULL; wd->ssurface = NULL;
	free(wd);
	free((void*)window);
}

/*function called to redraw the window*/
static void refresh_s(const Window_t* window){
	windowdata* wd = (windowdata*) window->data;
	SDL_UpdateWindowSurface( wd->window);
}

/*function to change the current surface the window is using*/
static void draw_image_surface_s(const Window_t* window, void* new_surface){
	windowdata* wd = (windowdata*)window->data;
	/*use inputed surface to draw on current surface*/
	SDL_BlitSurface((SDL_Surface*)new_surface, NULL, wd->ssurface, NULL);
}


const Window_t* create_window(char* windowtitle, int swidth, int sheight){
	/*create a window,but only if enough memory*/
	Window_t* sdlwindow = (Window_t*)malloc(sizeof(Window_t));
	if( sdlwindow != NULL){
		/*set the data members with malloc'd struct*/
		windowdata* wd = (windowdata*)malloc(sizeof(windowdata));
		if( wd != NULL){
			/*setup screen width and height to user input, unless 0 then default*/
			wd->width = (swidth > 0) ? swidth : DEF_WIDTH;
			wd->height = (sheight > 0 ) ? sheight : DEF_HEIGHT; 

			/*now set up SDL stuff*/
			wd->window = SDL_CreateWindow(windowtitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
										wd->width, wd->height, SDL_WINDOW_SHOWN );			
			wd->ssurface = SDL_GetWindowSurface( wd->window);

			/*draw the screen...*/
			SDL_FillRect( wd->ssurface, NULL, SDL_MapRGB( wd->ssurface->format, 0xFF, 0xFF, 0xFF ) );
			
			sdlwindow->data = wd;
			/*set up window functions*/
			sdlwindow->refresh = refresh_s;
			sdlwindow->destroy_window = destroy_window_s;

			sdlwindow->draw_image_surface = draw_image_surface_s;
		} else {
			/*free resources allocated if data cannot be managed*/
			free(sdlwindow);
			sdlwindow = NULL;
			return NULL;
		}
	} else {
		return NULL;
	}
	return sdlwindow;
}

