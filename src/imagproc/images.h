#ifndef _INCLUDED_IMAGES_H
#define _INCLUDED_IMAGES_H

typedef struct Surfaces_t Surfaces_t;

/*creates and stores sdl surfaces*/
const Surfaces_t create_surface(char* file);

/* TODO
	version 1.0 uses arrays
		test performance of ARRAY 
		vs LINKED LIST vs QUEUE
*/

typedef struct Surfaces_t{

	void* data;


} Surfaces_t;



#endif