#include "burlap.h"

#define EXIT 0


struct Player {
	int x;
	int y;
};
	
void mvplayer(int input, struct Player player);

int main(void)
{
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

	int screenx, screeny;

	getmaxyx(stdscr, screenx, screeny);
	struct Player player;

	player.x = screenx / 2;
	player.y = screeny / 2;

	while (!EXIT) {
		mvplayer((int) getch(), player); 
	}
}

void mvplayer(int input, struct Player player)
{
	switch (input) {
	
	}
}
