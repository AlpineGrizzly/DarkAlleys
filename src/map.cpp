#include <cmath>
#include <ncurses.h>
#include <iostream>

#include "map.h"

const char* g_grass_text[] = {GRASS_1, GRASS_2, GRASS_3, GRASS_4};  

/** pos struct for defining positions on the map */
typedef struct { 
    int x;
    int y;
    int dimx;
    int dimy;  
} house_t;


/** Helper functions */
static void laygrass(char* map[][MAP_Y]) {
    for (int y = 1; y < MAP_Y - 1; y++) { 
        for (int x = 1; x < MAP_X - 1; x++) {
             map[x-1][y-1] = (char*)g_grass_text[rand() % 4];
        }
    }
}

static void paveroads(char* map[][MAP_Y]) { 
    int roads[] = {3, 11, 30}; //hardcoded
    int nroads = sizeof(roads) / sizeof(roads[0]);
    
    // Draw roads
    for (int r = 0; r < nroads; r++) { 
        for (int y = 0; y < MAP_Y; y++) { 
            for (int x = 0; x < MAP_X; x++) {
                if (y == roads[r])
                    map[x][y] = (char*)ROAD_INNER;
                else if (y == roads[r] - 1 || y == roads[r] + 1)
                    map[x][y] = (char*)ROAD_OUTER;
            }
        }
    }
}

// gendim Generate a random dimension for a structure between min and max structure size
static int get_dim() { 
    return rand() % (MAX_SSIZE - MIN_SSIZE + 1) + MIN_SSIZE;
}

static void gen_struct(int dimx, int dimy, char* foundation[][MAX_SSIZE]) { 
    // Generate the doors
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

// Generates a random house structure
static bool gen_house(house_t *dahood, int idx) {
    house_t tmp;

    // Get dimensions
    tmp.dimx = get_dim();
    tmp.dimy = get_dim();

    // Get position on map that doesn't conflict with other houses
    tmp.x = 1 + (rand() % (MAP_X - tmp.dimx));
    tmp.y = 1 + (rand() % (MAP_Y - tmp.dimy));

    dahood[idx] = tmp;
    return true;
}

static void build_structs(char* map[][MAP_Y]) {
    char* foundation[MAX_SSIZE][MAX_SSIZE] = {0}; // Used to generate our array 
    int num_house = 5; // Number of buildings to generate

    /** Contains positions for each structure generated */
    house_t house[num_house];

    // Generate the buildings 
    for (int i = 0; i < num_house; i++) {
        // Generate the building
        if (!gen_house(house, i))
            break;

        // Build the structure on the foundation
        gen_struct(house[i].dimx, house[i].dimy, foundation);        
        
        // Put the foundationed house on the map 
        for (int y = 0; y < house[i].dimy; y++) { 
            for(int x = 0; x < house[i].dimx; x++) {
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
    init_pair(C_INDUSTRIAL, COLOR_BLUE, COLOR_BLACK);
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