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

int main() { 
    /* Init vars */
    char mesg[] = "Here is some text!";
    int max_y, max_x;

    /* Initialize ncurses */
    initscr();
    cbreak();
    noecho();
    curs_set(0); // Hide the cursor

    /* Get screen size */ 
    getmaxyx(stdscr, max_y, max_x);
    
    /* Create the main window */ 
    WINDOW* playwin = newwin(20 ,50, 0, 0);
    box(playwin, '|', '=');   
    refresh();
    wrefresh(playwin);

    Player* p = new Player(playwin, 1, 1, '@');
    do { 
        p->display();
        wrefresh(playwin);
    } while(p->getmv() != 'x');

    endwin();

	return 0;
}
