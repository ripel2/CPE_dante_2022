/*
** EPITECH PROJECT, 2022
** dante_generator
** File description:
** dante_generator
*/

#include "generator.h"

void binary_tree_carve(btree_lines_t *btree, uint32_t height, bool perfect)
{
    char dirs;

    for (uint32_t y = 0; y < height; y += 2) {
        dirs = 0b0000;
        btree_cpy_grid(btree);
        for (uint32_t x = 0; x < btree->width; x += 2) {
            get_valid_directions(x, y, &dirs);
            carve_side_walls(btree, x, y, dirs);
            carve_directions(btree, x, y, dirs);
        }
        if (!perfect) {
            carve_random_blocks(btree);
        }
        if (height % 2 == 0 || y + 2 < height) {
            btree_print_lines(btree);
        }
    }
}

int generate_maze(uint32_t width, uint32_t height, bool is_perfect)
{
    btree_lines_t btree = {0};

    if (init_btree(&btree, width) == MALLOC_ERROR) {
        return (MALLOC_ERROR);
    }
    binary_tree_carve(&btree, height, is_perfect);
    carve_last_line(&btree, height, is_perfect);
    destroy_btree(&btree);
    return (NO_ERRORS);
}
