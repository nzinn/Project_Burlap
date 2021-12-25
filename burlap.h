#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

#ifndef BURLAP_H
#define BURLAP_H

struct Player;
// creates a player and sets default poisition and health
struct Player *wcreate_player(WINDOW *window);

//takes a keypress and updates the players position within the current window
int mvplayer(struct Player *player, int keypress);

void get_player_pos(struct Player *player, int *y, int *x);
#endif
