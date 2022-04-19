/*
** EPITECH PROJECT, 2022
** generator.h
** File description:
** generator.h
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define NO_ERRORS 0
#define MALLOC_ERROR 1

#define TOP_LINE 0
#define BOTTOM_LINE 1

#define WALL_CHAR 'X'
#define EMPTY_CHAR '*'

#define NORTH 0b0001
#define SOUTH 0b0010
#define EAST 0b0100
#define WEST 0b1000

typedef struct {
    bool is_first_line;
    bool is_last_line;
    uint32_t width;
    char *lines[2];
} btree_lines_t;

int generate_maze(uint32_t width, uint32_t height, bool is_perfect);

int init_btree(btree_lines_t *, uint32_t width);
void btree_cpy_grid(btree_lines_t *);
void btree_print_lines(btree_lines_t *);
void destroy_btree(btree_lines_t *);

void get_valid_directions(uint32_t x, uint32_t y, char *dirs);
void carve_random_blocks(btree_lines_t *);
void carve_side_walls(btree_lines_t *, uint32_t x, uint32_t y, char dirs);
void carve_directions(btree_lines_t *, uint32_t x, uint32_t y, char dirs);
void carve_last_line(btree_lines_t *btree, uint32_t height, bool perfect);
