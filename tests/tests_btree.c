/*
** EPITECH PROJECT, 2022
** dante_generator tests
** File description:
** dante_generator tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "generator.h"

Test(init_btree, init_btree)
{
    btree_lines_t btree = {0};

    init_btree(&btree, 1);
    cr_assert_not_null(btree.lines[0]);
    cr_assert_not_null(btree.lines[1]);
    cr_assert_eq(btree.width, 3);
    cr_assert(btree.is_first_line);
    cr_assert_not(btree.is_last_line);
    free(btree.lines[0]);
    free(btree.lines[1]);
}

Test(btree_cpy_grid, btree_cpy_grid)
{
    btree_lines_t btree = {0};

    init_btree(&btree, 4);
    btree_cpy_grid(&btree);
    cr_assert_str_eq(btree.lines[TOP_LINE], "XXXXXX\n");
    cr_assert_str_eq(btree.lines[BOTTOM_LINE], "*X*X*X\n");
    destroy_btree(&btree);
}

Test(btree_print_lines, btree_do_not_print_first_line,
.timeout = 5, .init = cr_redirect_stdout)
{
    btree_lines_t btree = {0};

    init_btree(&btree, 4);
    btree_cpy_grid(&btree);
    btree_print_lines(&btree);
    cr_assert_stdout_eq_str("*X*X\n");
    destroy_btree(&btree);
}

Test(btree_print_lines, btree_print_lines,
.timeout = 5, .init = cr_redirect_stdout)
{
    btree_lines_t btree = {0};

    init_btree(&btree, 4);
    btree.is_first_line = false;
    btree_cpy_grid(&btree);
    btree_print_lines(&btree);
    cr_assert_stdout_eq_str("XXXX\n*X*X\n");
    destroy_btree(&btree);
}

Test(destroy_btree, destroy_btree)
{
    btree_lines_t btree = {0};

    init_btree(&btree, 1);
    destroy_btree(&btree);
}
