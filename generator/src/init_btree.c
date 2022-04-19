/*
** EPITECH PROJECT, 2022
** dante_generator
** File description:
** dante_generator
*/

#include "generator.h"

int init_btree(btree_lines_t *btree, uint32_t width)
{
    btree->is_first_line = true;
    btree->is_last_line = false;
    btree->width = width + 2;
    btree->lines[0] = calloc(sizeof(char), (btree->width + 2));
    btree->lines[1] = calloc(sizeof(char), (btree->width + 2));
    if (btree->lines[0] == NULL || btree->lines[1] == NULL) {
        free(btree->lines[0]);
        free(btree->lines[1]);
        return (MALLOC_ERROR);
    }
    return (NO_ERRORS);
}

void btree_cpy_grid(btree_lines_t *btree)
{
    for (uint32_t c = 0; c < btree->width; c++) {
        if (c % 2 == 0) {
            btree->lines[BOTTOM_LINE][c] = EMPTY_CHAR;
        } else {
            btree->lines[BOTTOM_LINE][c] = WALL_CHAR;
        }
    }
    btree->lines[BOTTOM_LINE][btree->width] = '\n';
    memset(btree->lines[TOP_LINE], WALL_CHAR, btree->width);
    btree->lines[TOP_LINE][btree->width] = '\n';
}

void btree_print_lines(btree_lines_t *btree)
{
    btree->lines[TOP_LINE][btree->width - 2] = '\n';
    btree->lines[TOP_LINE][btree->width - 1] = '\0';
    btree->lines[BOTTOM_LINE][btree->width - 2] = '\n';
    btree->lines[BOTTOM_LINE][btree->width - 1] = '\0';
    if (btree->is_first_line) {
        btree->is_first_line = false;
    } else {
        write(1, btree->lines[TOP_LINE], btree->width - 1);
    }
    write(1, btree->lines[BOTTOM_LINE], btree->width - 1);
}

void destroy_btree(btree_lines_t *btree)
{
    free(btree->lines[0]);
    free(btree->lines[1]);
}
