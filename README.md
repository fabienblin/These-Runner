# These Runner
This is a simple maze game where you will use ZQSD to escape before your time runs out.

## Usage
`./thesesRunner.exe X_SIZE Y_SIZE`

## Compilation
1. Compile the libGrid with `make`.
2. Compile the game with `make`.
3. Run the game as descibed in **Usage**.

## More
The maze is generated using a recursive depth first search algorithm, a classic for this type of generator.

You may uncomment `print_grid(maze); usleep(333);` inside the `recursive_depth_first` function to see the maze generate.