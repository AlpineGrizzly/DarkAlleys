/**********************
 * DarkAlleys
 * Terminal style game about 
 * running a bitcoin mining 
 * operation to get rich and shit
 *
 * Author R3V
 **********************/
#include <string>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>

#include "player.h"
#include "map.h"

int main() { 
    /* Init vars */
    int max_y, max_x;
    srand (time(NULL)); // Initializes map seed

    /* Initialize ncurses */
    initscr();
    cbreak();
    noecho();
    curs_set(0); // Hide the cursor

    /* Get screen size */ 
    getmaxyx(stdscr, max_y, max_x);
    
    /* Create the main window */ 
    WINDOW* playwin = newwin(MAP_Y, MAP_X, 0, 0);
    box(playwin, '|', '=');   
    Map* map = new Map(playwin);
    map->gen_map();
    refresh();
    wrefresh(playwin);

    Player* p = new Player(playwin, 1, 1, '@');
    do { 
        map->draw_map();
        p->display();
        wrefresh(playwin);
    } while(p->getmv() != 'x');

    endwin();

	return 0;
}
