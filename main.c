#include "burlap.h"

#define EXIT 0

#define MV_SPEED 1
	

int main(void)
{
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

	curs_set(0);
	struct Player *player = wcreate_player(stdscr);

	ptplayer(stdscr, player);

	int input;

	while ((input = getch()) != 'q') {
		switch (input) {

		case KEY_LEFT:
			mvplayer(stdscr, player, 0, -1 * MV_SPEED);
			break;
		case KEY_RIGHT:
			mvplayer(stdscr, player, 0, MV_SPEED);
			break;
		case KEY_UP:
			mvplayer(stdscr, player, -1 * MV_SPEED, 0);
			break;
		case KEY_DOWN:
			mvplayer(stdscr, player, MV_SPEED, 0);
		}
		clrplayer(stdscr, player);
		ptplayer(stdscr, player);
	}

	endwin();
}

