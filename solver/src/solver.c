/*
** EPITECH PROJECT, 2022
** dante_solver
** File description:
** dante_solver
*/

#include "solver.h"

queue_n_t *get_first_node(queue_t *queue, maze_t *maze)
{
    queue_n_t *node = queue->first_node;

    while (node != NULL) {
        if (!GOT_VISITED(maze->nodes[node->y][node->x])) {
            return (node);
        }
        node = node->next;
    }
    return (NULL);
}

void follow_up_queue(maze_t *maze, queue_n_t *tail)
{
    while (tail != NULL) {
        maze->nodes[tail->y][tail->x] |= CORRECT_PATH;
        tail = tail->prev;
    }
}

int solve_maze(maze_t *maze, queue_t *queue)
{
    queue_n_t *current = get_first_node(queue, maze);
    int status = NO_ERRORS;

    while (current != NULL) {
        maze->nodes[current->y][current->x] |= VISITED_BIT;
        if (current->x == maze->width - 1 &&
        current->y == maze->height - 1) {
            follow_up_queue(maze, current);
            return (NO_ERRORS);
        }
        status = add_new_neighbors(maze, queue, current);
        if (status != NO_ERRORS)
            return (status);
        current = get_first_node(queue, maze);
    }
    return (NO_SOLUTIONS);
}

int solver(char *map_path)
{
    maze_t maze = {0};
    queue_t queue = {0};
    int load_status = load_maze(map_path, &maze);

    if (load_status != NO_ERRORS)
        return (load_status);
    load_status = init_queue(&queue);
    nodeify_maze(&maze);
    if (load_status != NO_ERRORS)
        return (load_status);
    load_status = solve_maze(&maze, &queue);
    if (load_status == NO_ERRORS) {
        print_solved_maze(&maze);
    } else if (load_status == NO_SOLUTIONS) {
        printf("no solution found");
        load_status = NO_ERRORS;
    }
    destroy_maze(&maze);
    free_queue(&queue);
    return (load_status);
}
