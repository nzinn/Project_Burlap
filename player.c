#include "burlap.h"

struct Player {
	struct Position {
		int x;
		int y;
	} pos;

	int health;
};

struct Player *wcreate_player(WINDOW *window)
{
	struct Player *player = (struct Player*) malloc(sizeof(struct Player));
	
	int winx, winy;
	getmaxyx(window, winy, winx);

	player->pos.x = winx / 2;
	player->pos.y = winy / 2;
	player->health = 100;
	return player;
}

//moves the player and returns FALSE if char is not a valid keypress
int mvplayer(struct Player *player, int keypress) 
{
	switch (keypress) {
	case KEY_LEFT:
		player->pos.x--;
		break;
	case KEY_RIGHT:
		player->pos.x++;
		break;
	//coords are flipped
	case KEY_DOWN:
		player->pos.y++;
		break;
	case KEY_UP:
		player->pos.y--;
		break;
	default:
		return 0;
	}

	return 1;
}

void get_player_pos(struct Player *player, int *y, int *x)
{
	*y = player->pos.y;
	*x = player->pos.x;
}

