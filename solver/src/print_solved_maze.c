/*
** EPITECH PROJECT, 2022
** dante_solver
** File description:
** dante_solver
*/

#include "solver.h"

void mazeify_line(maze_t *maze, uint32_t line)
{
    for (uint32_t x = 0; x < maze->width; x++) {
        if (IS_WALL(maze->nodes[line][x]))
            maze->nodes[line][x] = WALL_CHAR;
        else if (IS_CORRECT_PATH(maze->nodes[line][x]))
            maze->nodes[line][x] = CORRECT_PATH_CHAR;
        else
            maze->nodes[line][x] = EMPTY_CHAR;
    }
}

void print_solved_maze(maze_t *maze)
{
    for (uint32_t line = 0; line < maze->height; line++) {
        mazeify_line(maze, line);
        write(1, maze->nodes[line], maze->width);
        if (line + 1 < maze->height)
            write(1, "\n", 1);
    }
}
