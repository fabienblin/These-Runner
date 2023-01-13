#ifndef __THESE_RUNNER__
#define __THESE_RUNNER__

#include "libGrid.h"
#include <time.h>

extern coordinate *maze_entry;
extern coordinate *maze_exit;
extern int is_victory;
extern int nb_turns;

void generate_maze(grid *maze);

#endif