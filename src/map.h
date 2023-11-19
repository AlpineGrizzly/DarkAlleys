#include <cmath>
#include <string>
#include <locale.h>

/* Map definitions */
#define MAP_X 50
#define MAP_Y 20

/* Characters for drawing map */
const char* g_grass_text[] = {",", ".", "`"};   

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

Map::Map(WINDOW *win) { //, char map[][MAP_Y]) { 
    this->curwin = win;
    setlocale(LC_ALL, "");
}

// Generates the map 
void Map::gen_map() { 
    for (int y = 1; y < MAP_Y - 1; y++) { 
        for (int x = 1; x < MAP_X - 1; x++) {
             this->map[x-1][y-1] = (char*)g_grass_text[rand() % 3];
        }
    }
}

void Map::draw_map() { 
    for (int y = 1; y < MAP_Y - 1; y++) { 
        for (int x = 1; x < MAP_X - 1; x++) {
             mvwaddstr(curwin, y, x, this->map[x-1][y-1]);
        }
    }
}