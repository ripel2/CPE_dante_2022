
# Dante's star

Maze generation and solving algorithms

## About this project

This project is an introduction to graphs, procedural generation and path finding algorithms.
I used the binary tree algorithm for the generation and the BFS algorithm for the solving.

## How to use

First compile with the Makefile

```sh
make
```

You can generate a maze of a given size using
```sh
./generator/generator "width" "height" "perfect"
```
(the perfect argument is optionnal)

You can solve a maze using
```sh
./solver/solver path_to_maze
```

## Features

- Generate perfect and imperfect mazes
- Generate large mazes quickly and efficiently (10000x10000 in less than 3 seconds)
- Solve any type of mazes
- Prints an error message if no solution is found
