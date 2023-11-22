/* Map definitions */
#define MAP_X 100
#define MAP_Y 40

/* Nature definitions */
#define WATER    '~'
#define MOUNTAIN '^'
#define GRASS_1  "," 
#define GRASS_2  "." 
#define GRASS_3  "`" 
#define GRASS_4  " "

/* Structure definitions */
#define MAX_SSIZE 10
#define MIN_SSIZE  4
#define B_WALL    "#"
#define DOOR      "+"
#define ROOF      "0"

/* City definitions */
#define ROAD_OUTER "="
#define ROAD_INNER "-"
#define ALLEY      "*"

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

