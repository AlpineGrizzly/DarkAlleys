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
    const int h_x = 5; 
    const int h_y = 5; 
    
    char* simple_house[h_x][h_y] = {0};
    int num_house = 3;

    // Mason time
    for (int i = 0; i < h_y; i++) { 
        for (int j = 0; j < h_x; j++) { 
            if (i == 0 || i == (h_y - 1) || j == 0 || j == (h_x - 1)) { 
                simple_house[i][j] = (char*)B_WALL;
            }
        }
    }

    // Makes a single house
    //for (int y = 0; y < 5; y++) { 
    //    for (int x = 0; x < 5; x++) {
    //         map[x][y] = simple_house[x][y];
    //    }
    //}    

    // Place 3 random builds on the map 
    for (int i = 0; i < num_house; i++) { 
        int house_x = 1 + (rand() % (MAP_X - 6));
        int house_y = 1 + (rand() % (MAP_Y - 6));
        int house_door = 1 + (rand() % 3);

        // Draw the house on the map 
        for (int y = 0; y < h_y; y++) { 
            for(int x = 0; x < h_x; x++) {
                if (y == house_door) // Makes a front and backdoor (WONKY looking) 
                    continue;
                map[house_x + x][house_y + y] = simple_house[x][y];
            }
        }
    }
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