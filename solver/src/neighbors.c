/*
** EPITECH PROJECT, 2022
** dante_solver
** File description:
** dante_solver
*/

#include "solver.h"

queue_n_t *create_new_neighbor(void)
{
    queue_n_t *neighbor = malloc(sizeof(queue_n_t));

    if (neighbor == NULL)
        return (NULL);
    neighbor->next = NULL;
    neighbor->prev = NULL;
    return (neighbor);
}

void add_neighbor(queue_n_t *neighbor, maze_t *maze,
queue_t *queue, queue_n_t *current_node)
{
    if (!IS_WALL(maze->nodes[neighbor->y][neighbor->x]) &&
    !GOT_VISITED(maze->nodes[neighbor->y][neighbor->x])) {
        neighbor->prev = current_node;
        enqueue(queue, neighbor);
    } else {
        free(neighbor);
    }
}

bool set_neighbor_pos_direction(queue_n_t *ng, uint8_t dir,
queue_n_t *c_node, maze_t *maze)
{
    uint32_t x = c_node->x;
    uint32_t y = c_node->y;

    switch (dir) {
        case NORTH:
            modify_node_pos(ng, c_node->x, c_node->y - 1);
            return (y == 0 ? false : true);
        case SOUTH:
            modify_node_pos(ng, c_node->x, c_node->y + 1);
            return (y == maze->height - 1 ? false : true);
        case EAST:
            modify_node_pos(ng, c_node->x - 1, c_node->y);
            return (x == 0 ? false : true);
        case WEST:
            modify_node_pos(ng, c_node->x + 1, c_node->y);
            return (x == maze->width - 1 ? false : true);
    }
    return (true);
}

int add_new_neighbors(maze_t *maze, queue_t *queue, queue_n_t *current_node)
{
    uint8_t dir = NORTH;
    queue_n_t *neighbor;

    while (dir < 4) {
        neighbor = create_new_neighbor();
        if (neighbor == NULL)
            return (MALLOC_ERROR);
        if (!set_neighbor_pos_direction(neighbor, dir, current_node, maze)) {
            free(neighbor);
            dir++;
            continue;
        }
        add_neighbor(neighbor, maze, queue, current_node);
        dir++;
    }
    return (NO_ERRORS);
}
