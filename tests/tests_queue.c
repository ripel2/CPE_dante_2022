/*
** EPITECH PROJECT, 2022
** dante_solver tests
** File description:
** dante_solver tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "solver.h"

Test(init_queue, init_queue)
{
    queue_t queue = {0};

    if (init_queue(&queue) == MALLOC_ERROR)
        cr_assert_eq(0, 1);
    cr_assert_not_null(queue.first_node);
    cr_assert_null(queue.first_node->next);
    cr_assert_null(queue.first_node->prev);
    cr_assert_eq(queue.first_node->x, 0);
    cr_assert_eq(queue.first_node->y, 0);
}


Test(enqueue, enqueue)
{
    queue_t queue = {0};
    queue_n_t *node = malloc(sizeof(queue_n_t));

    if (init_queue(&queue) == MALLOC_ERROR || node == NULL)
        cr_assert_eq(0, 1);
    node->prev = NULL;
    node->next = NULL;
    node->x = 42;
    node->y = 42;
    enqueue(&queue, node);
    cr_assert_not_null(queue.first_node);
    cr_assert_not_null(queue.first_node->next);
    cr_assert_null(queue.first_node->prev);
    cr_assert_eq(queue.first_node->x, 42);
    cr_assert_eq(queue.first_node->next->x, 0);
    free_queue(&queue);
}

Test(modify_node_pos, modify_node_pos)
{
    queue_n_t node = {0};

    modify_node_pos(&node, 21, 42);
    cr_assert_eq(node.x, 21);
    cr_assert_eq(node.y, 42);
}