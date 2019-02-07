#ifndef _INCLUDED_SETTINGS_H
#define _INCLUDED_SETTINGS_H
#include <stdlib.h>

const char* default_menu_path = "./images/menu"

/*an enum to hold various default values*/
enum defaults_t{
	/*screen width*/
	DEF_WIDTH = 640,
	/*screen height*/
	DEF_HEIGHT = 480,
	DEF_NUM_MENUS = 6
};

/*an enum to hold various screens*/
enum screens_t{
	MAIN_MENU,
	SECOND_MENU,
	THIRD_MENU,
	FOURTH_MENU,
	FIFTH_MENU
};

/*list of menu items to parse*/


#endif