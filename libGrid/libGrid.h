#ifndef __LIBGRID__
#define __LIBGRID__

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define EMPTY_SYMBOL ' '
#define WALL_SYMBOL '#'
#define PLAYER_SYMBOL 'O'
#define EXIT_SYMBOL '$'

enum direction {
	TOP,
	BOT,
	LEFT,
	RIGHT
};

typedef struct coordinate {
	int x;
	int y;
	char symbol;
} coordinate;

typedef struct grid {
	int x;
	int y;
	coordinate ***array;
} grid;

// Grid functions
grid *new_grid(int x, int y);
void del_grid(grid **g);
void print_grid(grid *g);

// Coordinate functions
coordinate *new_coordinate();
void init_coordinate(coordinate *c, int x, int y, char s);
void del_coordinate(coordinate **c);
void print_coordinate(coordinate *c);
coordinate *get_coord_in_direction(grid *g, coordinate *c, enum direction dir);

// Util functions
int	is_coordinate_in_grid(grid *g, int x, int y);
char *get_direction(enum direction dir);

#endif