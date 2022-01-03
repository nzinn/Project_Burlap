#include "burlap.h"

struct Player {
	struct Position {
		int x;
		int y;
	} pos, prev_pos;

	int health;
	int speed;
};

struct Player *wcreate_player(WINDOW *window)
{
	struct Player *player = (struct Player*) malloc(sizeof(struct Player));
	
	int winx, winy;
	getmaxyx(window, winy, winx);

	player->pos.x = winx / 2;
	player->pos.y = winy / 2;
	player->health = 100;
	player->speed = 1;
	
	return player;
}

//moves the player by the specified amount, where positive y is down
int mvplayer(WINDOW *win, struct Player *player, int ymv, int xmv) 
{
	player->prev_pos.x = player->pos.x;
	player->prev_pos.y = player->pos.y;
	
	int xmax;
	int ymax;

	getmaxyx(win, ymax, xmax);

	//adjust for scrollbar
	xmax -= 3;

	//don't let player leave the window
	if (0 >= player->pos.x + xmv || player->pos.x + xmv >= xmax || 0 >= player->pos.y + ymv || player->pos.y + ymv >= ymax - 1)
	{
		return 1;
	}

	player->pos.x += xmv;
	player->pos.y += ymv;

	return 0;
}

void clear_player(WINDOW *win, struct Player *player)
{
	mvwaddch(win, player->prev_pos.y, player->prev_pos.x, ' ');
}

void put_player(WINDOW *win, struct Player *player)
{
	mvwaddch(win, player->pos.y, player->pos.x, 'R');
}

void get_player_pos(struct Player *player, int *y, int *x)
{
	*y = player->pos.y;
	*x = player->pos.x;
}

void set_player_speed(struct Player *player, int speed)
{
	player->speed = speed;
}

int get_player_speed(struct Player *player)
{
	return player->speed;
}
