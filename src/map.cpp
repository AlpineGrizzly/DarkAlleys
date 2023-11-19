#include <cmath>
#include <ncurses.h>

#include "map.h"

const char* g_grass_text[] = {GRASS_1, GRASS_2, GRASS_3, GRASS_4};  

/** Helper functions */
void laygrass(char* map[][MAP_Y]) {
    for (int y = 1; y < MAP_Y - 1; y++) { 
        for (int x = 1; x < MAP_X - 1; x++) {
             map[x-1][y-1] = (char*)g_grass_text[rand() % 4];
        }
    }
}

void paveroads(char* map[][MAP_Y]) { 
    // Need 2 implement 
}

void build_structs(char* map[][MAP_Y]) { 
    // Need 2 implement
}


/** Map function definitions */
Map::Map(WINDOW *win) { 
    this->curwin = win;

    /** Init color pairs */
    init_pair(C_NATURE, COLOR_GREEN, COLOR_BLACK); 
}

// Generates the map 
void Map::gen_map() {
    laygrass(this->map);      // Layer 1 grass + trees 
    paveroads(this->map);     // Layer 2 walkways and roads
    build_structs(this->map); // Layer 3 Buildings
}

void Map::draw_map() {
    wattron(this->curwin, COLOR_PAIR(C_NATURE));
    for (int y = 1; y < MAP_Y - 1; y++) { 
        for (int x = 1; x < MAP_X - 1; x++) {
             mvwaddstr(curwin, y, x, this->map[x-1][y-1]);
        }
    }
}