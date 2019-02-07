#include <SDL2/SDL.h>
#include "./window/window.h"
#include "settings.h"


SDL_Surface** load_array(char** images, int size){
	int i;
	/*get enough space in the sdl surface array and check to ensure malloc did not fail*/
	SDL_Surface** surfar = (SDL_Surface**)malloc(size * sizeof(SDL_Surface*));	
	if( surfar == NULL)
		return NULL;
	/*null out the surface array*/
	for( i = 0; i < size; i++ ){
		surfar[i] = NULL;
	}

	for( i = 0; i < size; i++){
		/*get menu name from menu array*/
		char* name = images[i];
		/*set the surface pointer to the image in the menu array*/
		surfar[i] = SDL_LoadBMP(name);
		/*check if the surface was successfully loaded*/
		if( surfar[i] == NULL)
			printf("Error loading %s\n",name);
	}
	return surfar;
}

char** create_the_menuarray(){
	char** m = (char**)malloc(6 * sizeof(char*));

	m[0] = "./images/main.bmp";
	m[1] = "./images/close.bmp";
	m[2] = "./images/left.bmp";
	m[3] = "./images/right.bmp";
	m[4] = "./images/up.bmp";
	m[5] = "./images/down.bmp";

	return m;
}


int main( void){
		
		/*create sdl instance*/
		SDL_Init( SDL_INIT_EVERYTHING);
		if( SDL_INIT_VIDEO  < 0)
			printf( "SDL could not be initialized: %s\n", SDL_GetError() );


		/*create window and refresh*/
		const Window_t* window = create_window("Test123", 707,900);
		window->refresh(window);

		SDL_Event eventhandler;

		SDL_Surface* hellosurface = SDL_LoadBMP("./images/B4C.bmp");
		int quit = 0;
		

		char** menus = create_the_menuarray();
		
		/*init an sldsurface pointer array to store values needed*/
		SDL_Surface** SurfaceArray = load_array(menus, DEF_NUM_MENUS);

		while( !quit){

			while(SDL_PollEvent(&eventhandler) != 0){

				if(eventhandler.type == SDL_QUIT){

					quit = 1;
				}
			}
		}
		window->draw_image_surface(window, hellosurface);
		window->refresh(window);
		SDL_Delay(2000);



	window->destroy_window(window);
	SDL_FreeSurface(hellosurface);
	hellosurface = NULL;
	SDL_Quit();

	return 0;
}