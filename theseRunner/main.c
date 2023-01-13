#include "theseRunner.h"

coordinate *maze_entry = NULL;
coordinate *maze_exit = NULL;
int is_victory = 0;
int nb_turns = 0;

int key_bindings(char key) {
	if (key == 'z') {
		return TOP;
	}
	else if (key == 'q') {
		return LEFT;
	}
	else if (key == 's') {
		return BOT;
	}
	else if (key == 'd') {
		return RIGHT;
	}
	else {
		return -1;
	}
}

coordinate *move_player(grid *maze, coordinate *player_pos, enum direction dir) {
	coordinate *new_pos = get_coord_in_direction(maze, player_pos, dir);
	if (new_pos == NULL) {
		return player_pos;
	}

	// collision 
	if (new_pos->symbol == WALL_SYMBOL){
		return player_pos;
	}

	// victory
	if (new_pos->symbol == EXIT_SYMBOL) {
		is_victory = 1;
	}

	player_pos->symbol = EMPTY_SYMBOL;
	new_pos->symbol = PLAYER_SYMBOL;

	return new_pos;
}

int main (int argc, char **argv){
	srand( time( NULL ) );
	grid *maze = new_grid(atoi(argv[1]), atoi(argv[2]));
	maze_entry = maze->array[1][1];

	generate_maze(maze);
	
	maze_entry->symbol = PLAYER_SYMBOL;
	maze_exit->symbol = EXIT_SYMBOL;
	nb_turns = (maze->x * maze->y) / 2;

	print_grid(maze);
	printf("You have %d turns remaining to find the exit.", nb_turns);
	printf("You start at ");
	print_coordinate(maze_entry);
	printf("You must go to ");
	print_coordinate(maze_exit);
	printf("Use ZQSD to find the exit\n");

	coordinate * player_position = maze_entry;
	char key[1];
	while (read(1, key, 1) != -1) {
		int dir = key_bindings(*key);
		if (dir == -1)
			continue;

		player_position = move_player(maze, player_position, dir);
		if (is_victory || nb_turns == 0){
			break;
		}

		print_grid(maze);
		printf("You have %d turns remaining to find the exit.", nb_turns);
		print_coordinate(player_position);
		print_coordinate(maze_exit);
		nb_turns--;
	}

	if (is_victory) {
		printf("\nVICTORY ! You won the game.\n");
	}
	else if (nb_turns == 0) {
		printf("\nEND OF TIME ! You lost the game.\n");
	}

	del_grid(&maze);
	return 0;
}

