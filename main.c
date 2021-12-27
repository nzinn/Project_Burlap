#include "burlap.h"

#define EXIT 0

#define MV_SPEED 1

//size of player window
#define PLAYER_WIN_X_SCALE .6
#define PLAYER_WIN_Y_SCALE .8

//padding between all windows in rows / columns
#define WIN_PADDING 4 

int main(void)
{
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

	curs_set(0);

	int xmax, ymax;

	getmaxyx(stdscr, ymax, xmax);
	
	WINDOW* player_win = newwin(ymax - WIN_PADDING * 2, xmax * PLAYER_WIN_X_SCALE - WIN_PADDING, WIN_PADDING, xmax * (1 - PLAYER_WIN_X_SCALE) - WIN_PADDING);
	wborder(player_win, '#', '#', '#', '#', '#', '#', '#', '#');
	wrefresh(stdscr);
	wrefresh(player_win);

	struct Player *player = wcreate_player(player_win);
	ptplayer(player_win, player);

	int input;

	while ((input = getch()) != 'q') {
		switch (input) {

		case KEY_LEFT:
			mvplayer(player_win, player, 0, -1 * MV_SPEED);
			break;
		case KEY_RIGHT:
			mvplayer(player_win, player, 0, MV_SPEED);
			break;
		case KEY_UP:
			mvplayer(player_win, player, -1 * MV_SPEED, 0);
			break;
		case KEY_DOWN:
			mvplayer(player_win, player, MV_SPEED, 0);
		}
		clrplayer(player_win, player);
		ptplayer(player_win, player);
		wrefresh(player_win);
	}

	endwin();
}

