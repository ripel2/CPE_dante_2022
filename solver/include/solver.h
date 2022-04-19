/*
** EPITECH PROJECT, 2022
** solver.h
** File description:
** solver.h
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
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

typedef char node_t;

#define WALL_CHAR 'X'
#define EMPTY_CHAR '*'
#define CORRECT_PATH_CHAR 'o'

enum errors {
    NO_SOLUTIONS = -1,
    NO_ERRORS,
    MALLOC_ERROR,
    READ_ERROR,
    OPEN_ERROR,
    STAT_ERROR,
    INVALID_MAZE_ERROR,
    IS_DIRECTORY_ERROR,
    INVALID_ARGUMENTS_ERROR,
    UNKNOWN_ERROR
};

enum directions {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

typedef struct s_maze{
    uint32_t width;
    uint32_t height;
    char **nodes;
} maze_t;

typedef struct s_queue_n {
    uint32_t x;
    uint32_t y;
    int32_t cost;
    struct s_queue_n *prev;
    struct s_queue_n *next;
} queue_n_t;

typedef struct s_queue {
    queue_n_t *first_node;
} queue_t;

enum {
    WALL_BIT = 0b00000001,
    NORTH_BIT = 0b00000010,
    SOUTH_BIT = 0b00000100,
    EAST_BIT = 0b00001000,
    WEST_BIT = 0b00010000,
    VISITED_BIT = 0b00100000,
    CORRECT_PATH = 0b01000000,
};

#define IS_WALL(node) ((node & WALL_BIT) > 0)
#define GOT_VISITED(node) ((node & VISITED_BIT) > 0)
#define IS_CORRECT_PATH(node) ((node & CORRECT_PATH) > 0)

int solver(char *map_path);
int prg_error_message(char **av, int error);

int load_file_buffer(char **buf, char *path);
int load_maze(char *map_path, maze_t *map);
void destroy_maze(maze_t *maze);

bool recursive_solver(maze_t *maze, uint32_t x, uint32_t y);
void nodeify_maze(maze_t *maze);

void print_solved_maze(maze_t *maze);

int init_queue(queue_t *queue);
void modify_node_pos(queue_n_t *node, uint32_t x, uint32_t y);
void enqueue(queue_t *queue, queue_n_t *node);
size_t count_open_nodes(queue_t *queue);

int add_new_neighbors(maze_t *, queue_t *, queue_n_t *current_node);
void free_queue(queue_t *queue);
bool queue_is_empty(queue_t *queue);
