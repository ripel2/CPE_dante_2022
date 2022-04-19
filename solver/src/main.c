/*
** EPITECH PROJECT, 2022
** dante_solver
** File description:
** dante_solver
*/

#include "solver.h"

int main(int ac, char **av)
{
    int status = NO_ERRORS;

    if (ac != 2) {
        return (prg_error_message(av, INVALID_ARGUMENTS_ERROR));
    }
    status = solver(av[1]);
    if (status != NO_ERRORS) {
        return (prg_error_message(av, status));
    }
    return (0);
}
