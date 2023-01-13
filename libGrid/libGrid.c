#include "libGrid.h"

/*
 * Allocates and initialises a new grid structure of dimentions x by y
 */
grid *new_grid(int x, int y) {
	if (x < 1 || y < 1) {
		printf("New grid must be of dimension at least 1x1, %dx%d given.", x, y);
		return NULL;
	}
	grid *new = malloc(sizeof(grid));
	
	new->x = x;
	new->y = y;
	new->array = malloc(sizeof(coordinate **) * y);
	
	for (int i = 0; i < y; i++) {
		new->array[i] = malloc(sizeof(coordinate *) * x);
		for (int j = 0; j < x; j++) {
			new->array[i][j] = new_coordinate();
			init_coordinate(new->array[i][j], j, i, WALL_SYMBOL);
		}
	}

	return new;
}

/*
 * Free a grid structure
 */
void del_grid(grid **g) {
	if (!(*g))
		return;

	for (int i = 0; i < (*g)->y; i++) {
		for (int j = 0; j < (*g)->x; j++) {
			del_coordinate(&(*g)->array[i][j]);
		}
		free((*g)->array[i]);
	}
	free((*g)->array);

	free(*g);
	*g = NULL;
}

/*
 * Print a grid structure to the console
 */
void print_grid(grid *g) {
	if (!g)
		return;

	printf("Grid of size %d(x) by %d(y) :\n", g->x, g->y);
	for (int i = 0; i < g->y; i++) {
		for (int j = 0; j < g->x; j++) {
			printf("%c", g->array[i][j]->symbol);
		}
		printf("\n");
	}
}

/*
 * Allocates a new coordinate structure
 */
coordinate *new_coordinate() {
	return malloc(sizeof(coordinate));
}

/*
 * Initialises a new coordinate structure of dimentions x by y with symbol s
 */
void init_coordinate(coordinate *c, int x, int y, char s) {
	if (!c)
		return;

	c->x = x;
	c->y = y;
	c->symbol = s;
}

/*
 * Free a coordinate structure
 */
void del_coordinate(coordinate **c) {
	free((*c));
	*c = NULL;
}

/*
 * Print a coordinate structure to the console
 */
void print_coordinate(coordinate *c) {
	if (!c)
		return;

	printf("Coordinate of '%c' is %d(x) %d(y)\n", c->symbol, c->x, c->y);
}

/*
 * Returns 0 if coorinate is not in the grid limit, otherwise, returns 1
 * Positions in x and y start at 0
 */
int	is_coordinate_in_grid(grid *g, int x, int y) {
	if (!g)
		return 0;

	return (x >= 0 && x < g->x) && (y >= 0 && y < g->y);
}

coordinate *get_coord_in_direction(grid *g, coordinate *c, enum direction dir) {
	if (!g || !c)
		return NULL;

	if (dir == TOP && is_coordinate_in_grid(g, c->x, c->y - 1)) {
		return g->array[c->y - 1][c->x];
	}
	else if (dir == BOT && is_coordinate_in_grid(g, c->x, c->y + 1)) {
		return g->array[c->y + 1][c->x];
	}
	else if (dir == LEFT && is_coordinate_in_grid(g, c->x - 1, c->y)) {
		return g->array[c->y][c->x - 1];
	}
	else if (dir == RIGHT && is_coordinate_in_grid(g, c->x + 1, c->y)) {
		return g->array[c->y][c->x + 1];
	}
	else {
		return NULL;
	}
}

char *get_direction(enum direction dir) {
	if (dir == TOP)
		return "TOP";
	else if (dir == BOT)
		return "BOT";
	else if (dir == LEFT)
		return "LEFT";
	else if (dir == RIGHT)
		return "RIGHT";
	else
		return NULL;
}

