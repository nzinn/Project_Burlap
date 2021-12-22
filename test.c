#include <unistd.h>
#include <ncurses.h>

#define msleep(A) usleep((A) * 1000)
#define GRAVITY 5 
#define TIME_WINDOW 0.1
#define RESOLUTION 5 
void throw(int, int);
int main(void) 
{
	initscr();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	while (0)
	{
		int i;
		for (i = 0; i < 10; i++){
			if (!i){
				mvaddch(0, i, 219);
				refresh();
				msleep(100);
			} else {
				mvaddch(0, i - 1, ' ');
				mvaddch(0, i, 219);
				refresh();
				msleep(100);
			}
		}
		mvaddch(0, i - 1, ' ');
		refresh();
	}	

	throw(0, 0);

	msleep(1000);

	throw(5, 0);

	msleep(1000);

	throw(5, -5);
	getch();
	endwin();
	return 0;
}
//throws a character with x and y velocity in cursors/sec
void throw(int init_xvel, int init_yvel)
{
	int floor, side;

	int x = 0;
	int y = 10;

	getmaxyx(stdscr, floor, side);

	mvaddch(y, x, 'o');
	refresh();
	msleep(500);

	int yvel;
	for (int t = 0; x < side && y < floor; t++)
	{
		mvaddch(y, x, ' ');
		x = init_xvel * t * TIME_WINDOW * RESOLUTION;
		yvel = GRAVITY * t * TIME_WINDOW + init_yvel;
		y = yvel * t * TIME_WINDOW * RESOLUTION + 10;
		
		mvprintw(t, 150, "x:%d y:%d", x, y);
		mvaddch(y, x, 'o');
		refresh();
		msleep(1000 * TIME_WINDOW);
	}
}


