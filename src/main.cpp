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
#include <locale.h>

#include "player.h"
#include "map.h"

int main() { 
    /* Init vars */
    int max_y, max_x;
    srand (time(NULL)); // Initializes map seed
    setlocale(LC_ALL, "");

    /* Initialize ncurses */
    initscr();
    cbreak();
    noecho();
    curs_set(0); // Hide the cursor
    start_color();

    /* Get screen size */ 
    getmaxyx(stdscr, max_y, max_x);
    
    /* Create the main window */ 
    WINDOW* playwin = newwin(MAP_Y, MAP_X, 0, 0);
    WINDOW* statswin = newwin(MAP_Y, 40 , 0, MAP_X);

    // Box the windows 
    box(playwin, '|', '=');   
    box(statswin, '*', '*');   

    Map* map = new Map(playwin);
    map->gen_map();
    refresh();
    wrefresh(playwin);
    wrefresh(statswin);

    Player* p = new Player(playwin, 2, 2, '@');
    do { 
        map->draw_map();
        p->display();
        wrefresh(playwin);
        wrefresh(statswin);
        refresh();
    } while(p->getmv() != 'x');

    endwin();
    delwin(playwin);
    delwin(statswin);
	return 0;
}
