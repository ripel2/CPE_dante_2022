/*
** EPITECH PROJECT, 2022
** dante_solver
** File description:
** dante_solver
*/

#include "solver.h"

void destroy_maze(maze_t *maze)
{
    for (unsigned int c = 0; c < maze->height + 1; c++) {
        free(maze->nodes[c]);
    }
    free(maze->nodes);
}
