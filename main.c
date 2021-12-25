#include "burlap.h"

#define EXIT 0


	

int main(void)
{
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

	curs_set(0);
	struct Player *player = wcreate_player(stdscr);

	int player_x, player_y;
	get_player_pos(player, &player_y, &player_x);
	mvaddch(player_y, player_x, 'O');
	mvprintw(0, 50, "y:%d x:%d", player_y, player_x);
	refresh();
	while (mvplayer(player, (int) getch())) {

		mvaddch(player_y, player_x, ' ');
		get_player_pos(player, &player_y, &player_x);
		mvprintw(0, 50, "y:%d x:%d", player_y, player_x);

		mvaddch(player_y, player_x, 'O');
		
		//gets the cursor back into the reight position
		refresh();
	}
	endwin();
}

