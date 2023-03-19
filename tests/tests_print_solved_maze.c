/*
** EPITECH PROJECT, 2022
** dante_solver tests
** File description:
** dante_solver tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "solver.h"

Test(print_solved_maze, print_solved_maze, .timeout = 3, .init = cr_redirect_stdout)
{
    maze_t maze = {0};

    maze.width = 3;
    maze.height = 2;
    maze.nodes = malloc(sizeof(char *) * 2);
    maze.nodes[0] = malloc(sizeof(char) * 3);
    maze.nodes[0][0] = CORRECT_PATH;
    maze.nodes[0][1] = CORRECT_PATH;
    maze.nodes[0][2] = CORRECT_PATH;
    maze.nodes[1] = malloc(sizeof(char) * 3);
    maze.nodes[1][0] = WALL_BIT;
    maze.nodes[1][2] = CORRECT_PATH;
    print_solved_maze(&maze);
    cr_assert_stdout_eq_str("ooo\nX*o");
}
