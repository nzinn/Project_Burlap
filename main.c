#include "burlap.h"

#define EXIT 0


//size of player window
#define PLAYER_WIN_X_SCALE .6
#define PLAYER_WIN_Y_SCALE .8

//padding between all windows in rows / columns
#define WIN_PADDING 4 
void draw_border(WINDOW *window);

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

	draw_border(stdscr);
	wrefresh(stdscr);

	struct Player *player = wcreate_player(player_win);
	put_player(player_win, player);

	int input;

	while ((input = getch()) != 'q') {
		
		switch (input) {

		case KEY_LEFT:
			mvplayer(player_win, player, 0, -1 * get_player_speed(player));
			break;
		case KEY_RIGHT:
			mvplayer(player_win, player, 0, get_player_speed(player));
			break;
		case KEY_UP:
			mvplayer(player_win, player, -1 * get_player_speed(player), 0);
			break;
		case KEY_DOWN:
			mvplayer(player_win, player, get_player_speed(player), 0);
		}

		clear_player(player_win, player);
		put_player(player_win, player);

		wrefresh(player_win);

	}

	endwin();
}

void draw_border(WINDOW *win)
{
	int xmax, ymax;
	getmaxyx(win, ymax, xmax);

	for (int row = 0; row <= ymax; row++) {
		for (int col = 0; col <= xmax; col++) {
			if (col % 2 == 0 && (row == 0 || row == ymax - 1)) {
				mvwaddch(win, row, col, '#');
			} else if (col == 0 || col == xmax - 1) {
				mvwaddch(win, row, col, '#');
			}
		}
	}
}
	

