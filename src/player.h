/****************************
 * player.h
 * 
 * Class representing the playable character in the world
 ****************************/

#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "structures.h"

/* Macro color for player */
#define C_PERSON 2

class Player { 
    public:
        Player(WINDOW *win, int y, int x, char c);

        void mvup();
        void mvdown();
        void mvleft();
        void mvright();
        int getmv();
        void display();

    private:
        int xLoc, yLoc, xMax, yMax;
        char character;
        WINDOW * curwin;
};

Player::Player(WINDOW * win, int y, int x, char c) { 
    curwin = win;
    yLoc = y;
    xLoc = x;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
    init_pair(C_PERSON, COLOR_RED, COLOR_BLACK);
}

static bool can_move(char spot) { 
    char block[] = {B_WALL[0]}; //, DOOR[0]};
    int nblocks = sizeof(block) / sizeof(block[0]);

    // Check against block characters
    for (int i = 0; i < nblocks; i++) { 
        if (spot == block[i])
            return false;
    }
    return true;    
}

void Player::mvup() { 
    char ch = mvwinch(this->curwin, yLoc-1, xLoc) & A_CHARTEXT; 
    if (!can_move(ch))
        return;
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc--;
    if (yLoc < 1)
        yLoc = 1;
}

void Player::mvdown() {
    // Check if we have a unpassable character
    char ch = mvwinch(this->curwin, yLoc+1, xLoc) & A_CHARTEXT; 
    if (!can_move(ch))
        return;
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc++;
    if (yLoc > yMax-2)
        yLoc = yMax-2;
}

void Player::mvleft() { 
    char ch = mvwinch(this->curwin, yLoc, xLoc-1) & A_CHARTEXT; 
    if (!can_move(ch))
        return;
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc--;
    if (xLoc < 1)
        xLoc = 1;
}

void Player::mvright() { 
    char ch = mvwinch(this->curwin, yLoc, xLoc+1) & A_CHARTEXT; 
    if (!can_move(ch))
        return;
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc++;
    if (xLoc > xMax-2)
        xLoc = xMax-2;
}

int Player::getmv() { 
    int choice = wgetch(curwin);
    switch (choice) { 
        case KEY_UP:
            mvup();
            break;
        case KEY_DOWN:
            mvdown();
            break;
        case KEY_LEFT:
            mvleft();
            break;
        case KEY_RIGHT:
            mvright();
            break;
        default:
            break;
    }
    return choice;
}

void Player::display() { 
    wattron(this->curwin, COLOR_PAIR(C_PERSON));
    mvwaddch(curwin, yLoc, xLoc, character);
}

#endif