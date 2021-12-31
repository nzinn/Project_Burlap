#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

#ifndef BURLAP_H
#define BURLAP_H

struct Player;
// creates a player and sets default poisition and health
struct Player *wcreate_player(WINDOW *window);

/*
 * Moves the player by the specified amount, where positive ymx is 
 * down. Returns 1 if player would've moved outside of the window.
 */
int mvplayer(WINDOW *win, struct Player *player, int ymx, int xmx);

/*
 * Clears player character from the screen
 */
void clrplayer(WINDOW *win, struct Player *player);

/* 
 * Prints the player character to the window
 */
void ptplayer(WINDOW *win, struct Player *player);

void get_player_pos(struct Player *player, int *y, int *x);

void set_player_speed(struct Player *player, int speed);

int get_player_speed(struct Player *player);
#endif
