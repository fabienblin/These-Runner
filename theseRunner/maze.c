#include "theseRunner.h"



void shuffle(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

// By default the maze is full of WALL_SYMBOL
// We want to carve the path recursively
void recursive_depth_first(grid *maze, coordinate *c) {
    int random_direction[] = {TOP, BOT, LEFT, RIGHT};
    shuffle(random_direction, 4);
    // printf("%d %d %d %d\n", random_direction[0], random_direction[1], random_direction[2], random_direction[3]);
    
    int is_impasse = 0;
    for (int i = 0; i < 4; i++) {
        // on avance de 2 cases pour savoir si on peut creuser
        coordinate *test = c;
        test = get_coord_in_direction(maze, test, random_direction[i]);
        test = get_coord_in_direction(maze, test, random_direction[i]);
        if (test && test->symbol == WALL_SYMBOL) { //il n'y a pas de couloir deux cases plus loin, on creuse les 2
            c = get_coord_in_direction(maze, c, random_direction[i]);
            c->symbol = EMPTY_SYMBOL;
            c = get_coord_in_direction(maze, c, random_direction[i]);
            c->symbol = EMPTY_SYMBOL;

            is_impasse++;

            // we carve the next position
            // print_grid(maze);
            // usleep(333);
            recursive_depth_first(maze, c);
        }
    }
    
    // si is_impasse n'a pas été incrémenté ça veut dire qu'aucune direction n'a été creusée
    if (is_impasse == 0) {
        if (maze_exit == NULL) {
            maze_exit = c;
        }
        return;
    }


}

void generate_maze(grid *maze) {
    recursive_depth_first(maze, maze_entry);
}
