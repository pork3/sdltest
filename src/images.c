#include<stdlib.h>
#include <stdio.h>
#include <SDL2/SDL>
#include "images.h"
#include "../settings.h"

typedef struct surfacedata{

	char** filenames;
	int size;

} surfacedata;


/*this parses the config path for all files*/
static char** parse_files(char* file){

}

const Surfaces_t* create_surface(char* file){
	Surfaces_t* surfacesdl = (Surfaces_t*)malloc(sizeof(Surfaces_t));
	if( surfacesdl != NULL){

		surfacedata* sd = (surfacedata*)malloc(sizeof(surfacedata));
		if( sd != NULL){
			char** fn = parse_files(file);
		} else {
			free(surfacesdl); 
			surfacesdl =NULL;
		}
	} else {
		return NULL;
	}
}