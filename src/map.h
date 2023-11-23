#include "structures.h"

/* Map definitions */
#define MAP_X 100
#define MAP_Y 40

/** Macros for map colors */
#define C_NATURE     1
#define C_INDUSTRIAL 2

// Use to find character currently at at_topleft = mvinch(0, 0);
class Map { 
    public: 
        Map(WINDOW *win);// , char map[][MAP_Y]);
        void draw_map(); 
        void gen_map();

    private:
        char* map[MAP_X][MAP_Y]; /* Map we will draw for the game */
        WINDOW *curwin;         /* ncurses window to draw to s*/
};

