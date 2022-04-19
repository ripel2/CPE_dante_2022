/*
** EPITECH PROJECT, 2022
** dante_solver
** File description:
** dante_solver
*/

#include "solver.h"

int init_queue(queue_t *queue)
{
    queue_n_t *node = malloc(sizeof(queue_n_t));

    if (node == NULL)
        return (MALLOC_ERROR);
    node->x = 0;
    node->y = 0;
    node->prev = NULL;
    node->next = NULL;
    queue->first_node = node;
    return (NO_ERRORS);
}

void enqueue(queue_t *queue, queue_n_t *node)
{
    node->next = queue->first_node;
    queue->first_node = node;
}

void modify_node_pos(queue_n_t *node, uint32_t x, uint32_t y)
{
    node->x = x;
    node->y = y;
}

void free_queue(queue_t *queue)
{
    queue_n_t *node = queue->first_node;
    queue_n_t *temp;

    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

bool queue_is_empty(queue_t *queue)
{
    return (queue->first_node == NULL);
}
