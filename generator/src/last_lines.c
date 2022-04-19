/*
** EPITECH PROJECT, 2022
** dante_generator
** File description:
** dante_generator
*/

#include "generator.h"

void carve_even_height(btree_lines_t *btree, bool perfect)
{
    char bottom_right_block = btree->lines[BOTTOM_LINE][btree->width - 3];

    memset(btree->lines[TOP_LINE], WALL_CHAR, btree->width);
    carve_side_walls(btree, 0U, UINT32_MAX, NORTH);
    for (uint32_t x = 0; x < btree->width; x += 2) {
        carve_directions(btree, x, UINT32_MAX, NORTH);
    }
    btree->lines[TOP_LINE][btree->width - 3] = EMPTY_CHAR;
    if (bottom_right_block == WALL_CHAR && btree->width - 3 > 0U) {
        btree->lines[TOP_LINE][btree->width - 4] = EMPTY_CHAR;
    } else if (perfect) {
        btree->lines[TOP_LINE][btree->width - 4] = WALL_CHAR;
    }
    if (!perfect) {
        carve_random_blocks(btree);
    }
    write(1, btree->lines[TOP_LINE], btree->width - 2);
}

void carve_odd_height(btree_lines_t *btree, bool perfect)
{
    char top_right_block;

    top_right_block = btree->lines[TOP_LINE][btree->width - 3];
    btree->lines[BOTTOM_LINE][btree->width - 3] = EMPTY_CHAR;
    if (top_right_block == WALL_CHAR && btree->width - 3 > 0U) {
        btree->lines[BOTTOM_LINE][btree->width - 4] = EMPTY_CHAR;
    } else if (perfect) {
        btree->lines[BOTTOM_LINE][btree->width - 4] = WALL_CHAR;
    }
    if (!perfect) {
        carve_random_blocks(btree);
    }
    btree->lines[TOP_LINE][btree->width - 2] = '\n';
    btree->lines[TOP_LINE][btree->width - 1] = '\0';
    btree->lines[BOTTOM_LINE][btree->width - 2] = '\n';
    btree->lines[BOTTOM_LINE][btree->width - 1] = '\0';
    write(1, btree->lines[TOP_LINE], btree->width - 1);
    write(1, btree->lines[BOTTOM_LINE], btree->width - 2);
}

void carve_special_cases(btree_lines_t *btree, uint32_t height)
{
    char empty = EMPTY_CHAR;
    char newline = '\n';

    if (height == 1) {
        memset(btree->lines[TOP_LINE], EMPTY_CHAR, btree->width);
        write(1, btree->lines[TOP_LINE], btree->width - 2);
        return;
    }
    if (btree->width - 2 == 1) {
        write(1, &empty, 1);
        if (height % 2 == 1) {
            write(1, &newline, 1);
            write(1, &empty, 1);
        }
        return;
    }
}

void carve_last_line(btree_lines_t *btree, uint32_t height, bool perfect)
{
    if (height == 1 || btree->width - 2 == 1) {
        carve_special_cases(btree, height);
    } else if (height % 2 == 0) {
        carve_even_height(btree, perfect);
    } else {
        carve_odd_height(btree, perfect);
    }
}
