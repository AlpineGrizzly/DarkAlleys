#include <cmath>
#include <ncurses.h>
#include <iostream>

#include "map.h"
#include "structures.h"

const char* g_grass_text[] = {GRASS_1, GRASS_2, GRASS_3, GRASS_4};  


/** pos struct for defining positions on the map */
typedef struct { 
    int x;
    int y;  
} pos_t;

/** Helper functions */
static void laygrass(char* map[][MAP_Y]) {
    for (int y = 1; y < MAP_Y - 1; y++) { 
        for (int x = 1; x < MAP_X - 1; x++) {
             map[x-1][y-1] = (char*)g_grass_text[rand() % 4];
        }
    }
}

static void paveroads(char* map[][MAP_Y]) { 
    // Need 2 implement 
}

// Returns true if a building is tool close to current building
static bool claustaphobia() { 
 // Need 2 implement
    return false;
}

static void gen_struct(int dimx, int dimy, char* foundation[][MAX_SSIZE]) { 
    // Generate our doors
    int door = 1 + (rand() % (dimy - 2)); // Makes a front and backdoor (WONKY looking) 

    // Generate the building in the foundation buffer  
    for (int y = 0; y < dimy; y++) { 
        for (int x = 0; x < dimx; x++) {  
            if (y == door && (x == 0 || x == dimx-1))
                foundation[x][y] = (char*)DOOR;
            else if (y == 0 || y == (dimy - 1) || x == 0 || x == (dimx - 1))
                foundation[x][y] = (char*)B_WALL;
            else
                foundation[x][y] = (char*)ROOF;
        }
    }
}

static void build_structs(char* map[][MAP_Y]) {
    char* foundation[MAX_SSIZE][MAX_SSIZE] = {0}; // Used to generate our array 
    int num_house = 3; // Number of buildings to generate

    /** Contains positions for each house generated */
    pos_t house[num_house];

    // Generate the buildings on the map
    for (int i = 0; i < num_house; i++) {
        // Generate the building size
        int dimx = 5; //MIN_SSIZE + (rand() % MAX_SSIZE);
        int dimy = 5; //MIN_SSIZE + (rand() % MAX_SSIZE);
        gen_struct(dimx, dimy, foundation);

        // Generate the location on the map of the building
        // Check 1: Make sure we aren't overlapping another building 
        house[i].x = 1 + (rand() % (MAP_X - dimx));
        house[i].y = 1 + (rand() % (MAP_Y - dimy));
        
        //map[house[i].x][house[i].y] = (char*)"$"; 
        //continue; 
        // Draw the house on the map 
        for (int y = 0; y < dimy; y++) { 
            for(int x = 0; x < dimx; x++) {
                map[house[i].x + x][house[i].y + y] = foundation[x][y];
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