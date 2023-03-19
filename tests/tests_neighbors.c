/*
** EPITECH PROJECT, 2022
** dante_solver tests
** File description:
** dante_solver tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "solver.h"

Test(add_new_neighbors, add_new_neighbors)
{
    maze_t maze = {0};
    queue_t queue = {0};

    cr_assert_eq(load_maze("perfect", &maze), NO_ERRORS);
    cr_assert_eq(init_queue(&queue), NO_ERRORS);
    nodeify_maze(&maze);
    add_new_neighbors(&maze, &queue, queue.first_node);
    cr_assert_eq(queue.first_node->x, 1);
    cr_assert_eq(queue.first_node->y, 0);
    cr_assert_eq(queue.first_node->prev->x, 0);
    cr_assert_eq(queue.first_node->prev->y, 0);
}
