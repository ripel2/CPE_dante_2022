/*
** EPITECH PROJECT, 2021
** my_sokoban tests
** File description:
** my_sokoban tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "solver.h"

Test(prg_error_message, one_error, .timeout = 5, .init = cr_redirect_stderr)
{
    prg_error_message((char *[]){"prg", NULL}, MALLOC_ERROR);
    cr_assert_stderr_eq_str("prg: malloc error\n");
}

Test(prg_error_message, map_error, .timeout = 5, .init = cr_redirect_stderr)
{
    prg_error_message((char *[]){"prg", "maze", NULL}, INVALID_MAZE_ERROR);
    cr_assert_stderr_eq_str("prg: invalid maze \"maze\"\n");
}
