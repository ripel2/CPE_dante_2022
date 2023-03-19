/*
** EPITECH PROJECT, 2022
** dante_solver tests
** File description:
** dante_solver tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "solver.h"

Test(nodeify_maze, nodeify_maze)
{
    maze_t maze = {0};

    cr_assert_eq(load_maze("perfect", &maze), NO_ERRORS);
    nodeify_maze(&maze);
    cr_assert((maze.nodes[0][0] & WALL_BIT) == 0);
    cr_assert(maze.nodes[0][0] & EAST_BIT);
    cr_assert(maze.nodes[0][0] & SOUTH_BIT);
    cr_assert((maze.nodes[0][0] & NORTH_BIT) == 0);
    cr_assert((maze.nodes[0][0] & WEST_BIT) == 0);
    cr_assert(maze.nodes[1][1] & WALL_BIT);
    cr_assert(maze.nodes[1][1] & WEST_BIT);
    cr_assert(maze.nodes[1][1] & SOUTH_BIT);
    cr_assert(maze.nodes[1][1] & NORTH_BIT);
    cr_assert((maze.nodes[1][1] & EAST_BIT) == 0);
    cr_assert((maze.nodes[99][99] & WALL_BIT) == 0);
    cr_assert(maze.nodes[99][99] & WEST_BIT);
    cr_assert((maze.nodes[99][99] & SOUTH_BIT) == 0);
    cr_assert((maze.nodes[99][99] & NORTH_BIT) == 0);
    cr_assert((maze.nodes[99][99] & EAST_BIT) == 0);
    destroy_maze(&maze);
}
