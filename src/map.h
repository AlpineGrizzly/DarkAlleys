/* Map definitions */
#define MAP_X 100
#define MAP_Y 40

/* Characters for drawing map */
#define B_WALL   "#"
#define DOOR     'D'
#define WATER    '~'
#define MOUNTAIN '^'
#define GRASS_1  "," 
#define GRASS_2  "." 
#define GRASS_3  "`" 
#define GRASS_4  " "

/** Macros for map colors */
#define C_NATURE 1

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

