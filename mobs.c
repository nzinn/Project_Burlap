#include "burlap.h"

struct Mob {
	struct {
		int x;
		int y;
	} pos, prev_pos;

	int health;
	char appearance;

};

