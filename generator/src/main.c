/*
** EPITECH PROJECT, 2022
** dante_generator
** File description:
** dante_generator
*/

#include "generator.h"

int my_isnumber(char *str)
{
    for (int c = 0; str[c] != '\0'; c++) {
        if (!isdigit(str[c])) {
            return (0);
        }
    }
    return (1);
}

int error_handling(int ac, char **av)
{
    if (ac < 3) {
        fprintf(stderr, "%s: not enough arguments\n", av[0]);
        return (84);
    }
    if (ac > 4) {
        fprintf(stderr, "%s: too much arguments\n", av[0]);
        return (84);
    }
    if (!my_isnumber(av[1]) || !my_isnumber(av[2])) {
        fprintf(stderr,
        "%s: arguments 2 and 3 must be positive numbers\n", av[0]);
        return (84);
    }
    if (ac == 4 && strcmp(av[3], "perfect") != 0) {
        fprintf(stderr, "%s: argument 3 must be \"perfect\"\n", av[0]);
        return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    int status;
    uint32_t width;
    uint32_t height;

    if (error_handling(ac, av) == 84) {
        return (84);
    }
    srand((unsigned int)time(NULL));
    width = (uint32_t)atoi(av[1]);
    height = (uint32_t)atoi(av[2]);
    if (width == 0 || height == 0) {
        fprintf(stderr, "%s: width and height cannot be zero\n", av[0]);
        return (84);
    }
    status = generate_maze(width, height, ac == 4);
    if (status == MALLOC_ERROR) {
        fprintf(stderr, "%s: malloc error\n", av[0]);
        return (84);
    }
    return (NO_ERRORS);
}
