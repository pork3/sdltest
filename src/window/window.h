#ifndef _INCLUDED_WINDOW_H
#define _INCLUDED_WINDOW_H

typedef struct Window_t Window_t;

/*creates and returns a pointer to a window takes screen wideth and height*/
const Window_t* create_window(char* windowtitle, int swidth, int sheight);

/*struct to hold instance of SDL window*/
typedef struct Window_t{
	/*data pointer to a struct initialized on creation*/
	void* data;

	/*changes the current scree surface*/
	void (*draw_image_surface)(const Window_t* window, void* new_surface);

	/*function to refresh window*/
	void (*refresh)(const Window_t* window);

	/*function to free resources consumed by the window*/
	void (*destroy_window )(const Window_t* window);
} Window_t;

#endif