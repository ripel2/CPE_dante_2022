/*
** EPITECH PROJECT, 2022
** dante_solver tests
** File description:
** dante_solver tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "solver.h"

Test(load_maze, load_perfect_maze)
{
    maze_t maze = {0};

    cr_assert_eq(load_maze("perfect", &maze), NO_ERRORS);
    destroy_maze(&maze);
}

Test(load_maze, load_maze)
{
    maze_t maze = {0};

    cr_assert_eq(load_maze("imperfect", &maze), NO_ERRORS);
    destroy_maze(&maze);
}

Test(load_maze, load_directory)
{
    maze_t maze = {0};

    cr_assert_eq(load_maze("solver", &maze), IS_DIRECTORY_ERROR);
}

Test(load_maze, empty)
{
    maze_t maze = {0};

    cr_assert_eq(load_maze("empty", &maze), INVALID_MAZE_ERROR);
}

Test(load_maze, invalid_chars)
{
    maze_t maze = {0};

    cr_assert_eq(load_maze("invalid_chars", &maze), INVALID_MAZE_ERROR);
}

Test(load_maze, line_width_differs)
{
    maze_t maze = {0};

    cr_assert_eq(load_maze("invalid_chars", &maze), INVALID_MAZE_ERROR);
}
