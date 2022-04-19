/*
** EPITECH PROJECT, 2022
** dante_generator
** File description:
** dante_generator
*/

#include "generator.h"

void get_valid_directions(uint32_t x, uint32_t y, char *dirs)
{
    if (y == 0U && x == 0U) {
        return;
    }
    if (y > 0U) {
        *dirs |= NORTH;
    }
    if (x > 0U) {
        *dirs |= WEST;
    }
}

void carve_random_blocks(btree_lines_t *btree)
{
    int blocks_to_carve = btree->width * 2 / 4;
    int carved = 0;
    int x = 0;
    int y = 0;

    while (carved < blocks_to_carve) {
        x = rand() % (btree->width);
        y = rand() % 2;
        btree->lines[y][x] = EMPTY_CHAR;
        carved++;
    }
}

void carve_side_walls(btree_lines_t *btree, uint32_t x, uint32_t y, char dirs)
{
    if (y > 0 && (dirs & NORTH) && !(dirs & WEST)) {
        btree->lines[TOP_LINE][x] = EMPTY_CHAR;
    }
    if (x > 0 && !(dirs & NORTH) && (dirs & WEST)) {
        btree->lines[BOTTOM_LINE][x - 1] = EMPTY_CHAR;
    }
}

void carve_directions(btree_lines_t *btree, uint32_t x, uint32_t y, char dirs)
{
    int coin;

    if (dirs & (NORTH + WEST)) {
        coin = rand() % 2;
        if (x > 0 && coin) {
            btree->lines[BOTTOM_LINE][x - 1] = EMPTY_CHAR;
        } else if (y > 0 && !coin) {
            btree->lines[TOP_LINE][x] = EMPTY_CHAR;
        }
    }
}
