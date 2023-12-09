#include <cmath>
#include <ncurses.h>
#include <iostream>

#include "map.h"
#include "items.h"

const char* g_grass_text[] = {GRASS_1, GRASS_2, GRASS_3, GRASS_4};  
const int g_ngrass_tile = sizeof(g_grass_text) / sizeof(g_grass_text[0]);

/** Helper functions */
/**
 * laygrass
 * 
 * Plants trees and lays grass in the world
 * 
 * @param map The map we are generating
*/
static void laygrass(char* map[][MAP_Y]) {
    for (int y = 1; y < MAP_Y - 1; y++) { 
        for (int x = 1; x < MAP_X - 1; x++) {
             map[x-1][y-1] = (char*)g_grass_text[rand() % 4];
        }
    }
}

/**
 * paveroads
 * 
 * Will procedural generate roads for the map
 * 
 * @param map The map we are generating on 
*/
static void paveroads(char* map[][MAP_Y]) { 
    int hroad = 0;
    int vroad = 0;
    int hroad_spacing = 5;
    int vroad_spacing = 15;
    
    // Draw Horizontal roads
    while(true) { 
        hroad = hroad + hroad_spacing + (rand() % 6);
        if (hroad > (MAP_Y - 3))
            break;

        // Draw horizontal road across the map
        for (int x = 0; x < MAP_X-2; x++) {
            map[x][hroad] = (char*)ROAD;
            map[x][hroad+1] = (char*)ROAD;
        }
    } 

    // Draw vertical roads
    while(true) { 
        vroad = vroad + vroad_spacing + (rand() % 4); 
        if (vroad > (MAP_X - 3))
            break;
        
        for (int y = 0; y < MAP_Y-2; y++) {
            map[vroad][y] = (char*)ROAD;
            map[vroad+1][y] = (char*)ROAD;
        }
    }
}

/** 
 * get_dim 
 * Generate a random dimension for a structure 
 * between min and max structure size
 */ 
static int get_dim() { 
    return rand() % (MAX_SSIZE - MIN_SSIZE + 1) + MIN_SSIZE;
}

/**
 * is_grass
 * 
 * Boolean function to check whether a given block is a grass block
 * 
 * @param block Block we are checking
 * 
 * @return true if the block is a grass block, false otherwise
*/
static bool is_grass(char* block) { 
    for (int i = 0; i < g_ngrass_tile; i++) { 
        if (block == g_grass_text[i])
            return true;
    }
    return false;
}

/** 
 * get_lotdim 
 * 
 * Get the dimensions on the space in lot provided
 *
 * @param x Beginning x position of the space
 * @param y Beginning y position of the space
 * @param map the map
 * 
 * @return dim_t object containing the x and y dimensions of the space on the map
 */ 
static dim_t get_lotdim(int x, int y, char* map[][MAP_Y]) { 
    dim_t tmp = {0};

    // Get X dim
    for(int i = x; i < MAP_X - 2; i++) { 
        if (!is_grass(map[i][y]))
            break;
        tmp.x++;
    }

    // Get Y dim
    for(int i = y; i < MAP_Y - 2; i++) { 
        if (!is_grass(map[x][i]))
            break;
        tmp.y++;
    }
    return tmp; 

}

/**
 * ropeadope
 * 
 * Generate the building on the map with the sp
        char* get_character();ecified dimensions
 * 
 * @param startx Starting x position of the space 
 * @param starty Starting y position of the space 
 * @param dims dim_t object containing dimensions of the building to be constructed
 * @param map the map
*/
static void ropeadope(int startx, int starty, dim_t dims, char* map[][MAP_Y]) { 
    int finalx = startx + dims.x;
    int finaly = starty + dims.y; 
    int door_pos = starty+1;

    // Generate the building    
    for (int y = starty; y < finaly; y++) { 
        char* get_character();
        for(int x = startx; x < finalx; x++) { 
            if (y == door_pos && (x == startx || x == finalx-1))
                map[x][y] = (char*)DOOR;
            else if (x == startx || y == starty || x == finalx-1 || y == finaly-1)
                map[x][y] = (char*)B_WALL;
            else
                map[x][y] = (char*)B_INTERIOR; //(char*)ROOF;
        }
    }
}

/**
 * is_corner
 * 
 * Checks to see if a position on the map is a corner piece 
 * 
 * @param posx X position in map
 * @param poxy Y position in map
 * @param map  The map
 * 
 * @return true if the position is a corner, false otherwise
*/
static bool is_corner(int posx, int posy, char* map[][MAP_Y]) { 
    // Case 1: vertical edge cases
    if (posx == 0 && ((posy == 0) || map[posx][posy-1] == (char*)ROAD))
        return true;
    
    // Case 2: Horizontal edge cases
    if (posy == 0 && ((posx == 0) || map[posx-1][posy] == (char*)ROAD))
        return true;
    
    // Case 3: Nonedge cases
    if (map[posx-1][posy] == (char*)ROAD && map[posx][posy-1] == (char*)ROAD)
        return true;
    
    return false;
}

/**
 * build_structs
 * 
 * Handles generating all the structures on the map
 * 
 * @param map Map to generate structures on
*/
static void build_structs(char* map[][MAP_Y]) {
    dim_t bdim; // To hold dimensions of our building
    
    // Find spots that are not occupied by roads
    for (int y = 0; y < MAP_Y - 2; y++) { 
        for (int x = 0; x < MAP_X - 2; x++) { 
            // Check if its a grass and a corner piece 
            if (!is_grass(map[x][y]) || !is_corner(x,y, map)) continue;

            // Get the dimensions of the space
            bdim = get_lotdim(x, y, map);

            //Check against min 
            if (bdim.x < MIN_SSIZE || bdim.y < MIN_SSIZE)
                continue;

            // Odds of generating 1/3 [0,1,2]
            if (rand() % 2)
                continue;

            // Put a building in the lot 
            ropeadope(x, y, bdim, map);   
        }
    }
}

/** 
 * layitems
 * 
 * Will generate items randomly throughout the world
 * 
 * @param map Map to lay items in 
*/
static void layitems(char* map[][MAP_Y]) { 
    //Miner* miners[MAX_MINERS];
    Miner* test_miner = new Miner((char*)MINER, (char*)"Basic Miner", MINER_CHANCE, rand() % 3);

    // randomly generate inside buildings
    for (int y = 0; y < MAP_Y-2; y++) { 
        for (int x = 0; x < MAP_X-2; x++) { 
            if (map[x][y] == (char*)B_INTERIOR) {  
                if (!(rand() % test_miner->get_rarity())) 
                    map[x][y] = test_miner->get_char(); // Spawn miners 
                else if(!(rand() % COMPUTER_CHANCE)) 
                    map[x][y] = (char*)COMPUTER;        // Spawn Computer 
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
    init_pair(C_ROADS, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(C_MINER, COLOR_WHITE, COLOR_BLACK);
    init_pair(C_ROADS, COLOR_WHITE, COLOR_BLACK);
    init_pair(C_DOOR, COLOR_MAGENTA, COLOR_GREEN);
}


/**
 * get_color
 * 
 * Given a block on the map, return the associated color 
 * 
 * @param block Block we are determining color
 * 
 * @return the associated color value 
*/
static int get_color(char* block) { 
    if (is_grass(block))
        return C_NATURE;    
    else if (block == MINER || block == COMPUTER)
        return C_MINER;
    else if (block == ROAD)
        return C_ROADS;
    else if (block == DOOR)
        return C_DOOR;
    
    return C_INDUSTRIAL;
}

/** 
 * gen_map
 * 
 * Generates the map
*/
void Map::gen_map() { 
    laygrass(this->map);      // Layer 1 grass + trees   
    paveroads(this->map);     // Layer 2 walkways and roads
    build_structs(this->map); // Layer 3 Building
    layitems(this->map);      // Layer 4 Generate items
    
}

/** 
 * draw_map
 * 
 * Draws the game map 
*/
void Map::draw_map() { 
    wattron(this->curwin, COLOR_PAIR(C_NATURE));
    for (int y = 1; y < MAP_Y - 1; y++) { 
        for (int x = 1; x < MAP_X - 1; x++) { 
            wattron(this->curwin, COLOR_PAIR(get_color(this->map[x-1][y-1])));
            mvwaddstr(curwin, y, x, this->map[x-1][y-1]);
        }
    }
}