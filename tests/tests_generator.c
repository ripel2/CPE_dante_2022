/*
** EPITECH PROJECT, 2022
** dante_generator tests
** File description:
** dante_generator tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "generator.h"

Test(generate_maze, height_one, .timeout = 3, .init = cr_redirect_stdout)
{
    generate_maze(1U, 1U, true);
    cr_assert_stdout_eq_str("*");
}

Test(generate_maze, height_ten, .timeout = 3, .init = cr_redirect_stdout)
{
    generate_maze(10U, 1U, true);
    cr_assert_stdout_eq_str("**********");
}

Test(generate_maze, width_one, .timeout = 3, .init = cr_redirect_stdout)
{
    generate_maze(1U, 2U, true);
    cr_assert_stdout_eq_str("*\n*");
}

Test(generate_maze, two_by_two, .timeout = 3, .init = cr_redirect_stdout)
{
    generate_maze(2U, 2U, true);
    cr_assert_stdout_eq_str("**\nX*");
}
