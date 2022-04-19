/*
** EPITECH PROJECT, 2022
** dante_solver
** File description:
** dante_solver
*/

#include "solver.h"

void nodeify_node(maze_t *maze, uint32_t line, uint32_t x)
{
    node_t temp = 0b00000000;

    if (maze->nodes[line][x] == 'X')
        temp |= WALL_BIT;
    if (x > 0U && !IS_WALL(maze->nodes[line][x - 1]))
        temp |= WEST_BIT;
    if (line > 0U && !IS_WALL(maze->nodes[line - 1][x]))
        temp |= NORTH_BIT;
    if (x + 1U < maze->width && maze->nodes[line][x + 1] != WALL_CHAR)
        temp |= EAST_BIT;
    if (line + 1U < maze->height && maze->nodes[line + 1][x] != WALL_CHAR)
        temp |= SOUTH_BIT;
    maze->nodes[line][x] = temp;
}

void nodeify_maze(maze_t *maze)
{
    for (uint32_t line = 0; line < maze->height; line++) {
        for (uint32_t x = 0; x < maze->width; x++) {
            nodeify_node(maze, line, x);
        }
    }
}
