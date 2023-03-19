/*
** EPITECH PROJECT, 2022
** dante_generator tests
** File description:
** dante_generator tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "generator.h"

Test(get_valid_directions, get_valid_directions)
{
    char dirs = 0b0000;

    get_valid_directions(0U, 0U, &dirs);
    cr_assert_eq(dirs, 0);
    get_valid_directions(42U, 667U, &dirs);
    cr_assert_eq(dirs, NORTH | WEST);
    dirs = 0b0000;
    get_valid_directions(42U, 0U, &dirs);
    cr_assert_eq(dirs, WEST);
    dirs = 0b0000;
    get_valid_directions(0U, 69U, &dirs);
    cr_assert_eq(dirs, NORTH);
}

Test(carve_side_walls, carve_side_walls)
{
    btree_lines_t btree = {0};

    if (init_btree(&btree, 6U) == MALLOC_ERROR)
        cr_assert_fail("Malloc error");
    btree_cpy_grid(&btree);
    carve_side_walls(&btree, 0U, 0U, 0);
    cr_assert_str_eq(btree.lines[TOP_LINE], "XXXXXXXX\n");
    cr_assert_str_eq(btree.lines[BOTTOM_LINE], "*X*X*X*X\n");
    carve_side_walls(&btree, 2U, 0U, WEST);
    cr_assert_str_eq(btree.lines[TOP_LINE], "XXXXXXXX\n");
    cr_assert_str_eq(btree.lines[BOTTOM_LINE], "***X*X*X\n");
    carve_side_walls(&btree, 4U, 2U, NORTH);
    cr_assert_str_eq(btree.lines[TOP_LINE], "XXXX*XXX\n");
    cr_assert_str_eq(btree.lines[BOTTOM_LINE], "***X*X*X\n");
    destroy_btree(&btree);
}

Test(carve_side_walls, make_sure_bad_data_does_nothing)
{
    btree_lines_t btree = {0};

    if (init_btree(&btree, 6U) == MALLOC_ERROR)
        cr_assert_fail("Malloc error");
    btree_cpy_grid(&btree);
    carve_side_walls(&btree, 0U, 0U, NORTH | WEST);
    carve_side_walls(&btree, 2U, 2U, NORTH | WEST);
    carve_side_walls(&btree, 2U, 0U, NORTH | WEST);
    carve_side_walls(&btree, 0U, 2U, NORTH | WEST);
    carve_side_walls(&btree, 2U, 0U, NORTH);
    carve_side_walls(&btree, 0U, 2U, WEST);
    cr_assert_str_eq(btree.lines[TOP_LINE], "XXXXXXXX\n");
    cr_assert_str_eq(btree.lines[BOTTOM_LINE], "*X*X*X*X\n");
    destroy_btree(&btree);
}

Test(carve_directions, carve_directions)
{
    btree_lines_t btree = {0};

    if (init_btree(&btree, 6U) == MALLOC_ERROR)
        cr_assert_fail("Malloc error");
    btree_cpy_grid(&btree);
    for (int c = 0; c < 100; c++)
        carve_directions(&btree, 2U, 2U, NORTH | WEST);
    cr_assert_str_eq(btree.lines[TOP_LINE], "XX*XXXXX\n");
    cr_assert_str_eq(btree.lines[BOTTOM_LINE], "***X*X*X\n");
    destroy_btree(&btree);
}

Test(carve_directions, error_handling)
{
    btree_lines_t btree = {0};

    if (init_btree(&btree, 6U) == MALLOC_ERROR)
        cr_assert_fail("Malloc error");
    btree_cpy_grid(&btree);
    for (int c = 0; c < 100; c++)
        carve_directions(&btree, 0U, 0U, NORTH | WEST);
    cr_assert_str_eq(btree.lines[TOP_LINE], "XXXXXXXX\n");
    cr_assert_str_eq(btree.lines[BOTTOM_LINE], "*X*X*X*X\n");
    destroy_btree(&btree);
}

Test(carve_random_blocks, carve_random_blocks)
{
    btree_lines_t btree = {0};

    if (init_btree(&btree, 2U) == MALLOC_ERROR)
        cr_assert_fail("Malloc error");
    btree_cpy_grid(&btree);
    for (int c = 0; c < 100; c++)
        carve_random_blocks(&btree);
    cr_assert_str_eq(btree.lines[TOP_LINE], "****\n");
    cr_assert_str_eq(btree.lines[BOTTOM_LINE], "****\n");
    destroy_btree(&btree);
}
