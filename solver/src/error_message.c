/*
** EPITECH PROJECT, 2022
** dante_solver
** File description:
** dante_solver
*/

#include "solver.h"

int prg_error_message(char **av, int error)
{
    char *msg[] = {"", "malloc error", "read error", "open error",
    "file not found", "invalid maze", "path is a directory",
    "invalid arguments", "unknown", NULL};

    fprintf(stderr, "%s: ", av[0]);
    for (int c = 0; msg[c] != NULL; c++) {
        if (c == error)
            fprintf(stderr, "%s", msg[c]);
    }
    if (error == INVALID_MAZE_ERROR) {
        fprintf(stderr, " \"%s\"", av[1]);
    }
    fprintf(stderr, "\n");
    return (84);
}
