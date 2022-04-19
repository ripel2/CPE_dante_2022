/*
** EPITECH PROJECT, 2022
** dante_solver
** File description:
** dante_solver
*/

#include "solver.h"

#include <string.h>

bool line_is_valid(char *buf)
{
    for (int c = 0; buf[c] != '\0'; c++) {
        if (!(buf[c] == '\n' || buf[c] == '*' || buf[c] == 'X')) {
            return (false);
        }
    }
    return (true);
}

int process_line(maze_t *map, char *line, uint32_t count)
{
    if (line == NULL)
        return (MALLOC_ERROR);
    map->nodes = realloc(map->nodes, (count + 1) * sizeof(node_t *));
    if (strlen(line) > 1 && line[strlen(line) - 1] == '\n')
        line[strlen(line) - 1] = '\0';
    if (map->width == UINT32_MAX)
        map->width = strlen(line);
    else if (strlen(line) != map->width)
        return (INVALID_MAZE_ERROR);
    map->nodes[count] = strdup(line);
    if (map->nodes[count] == NULL)
        return (MALLOC_ERROR);
    if (line_is_valid(map->nodes[count]) == false)
        return (INVALID_MAZE_ERROR);
    return (NO_ERRORS);
}

int read_lines(maze_t *map, char *line, uint32_t count, FILE *fp)
{
    size_t line_size = 128;
    ssize_t read = getline(&line, &line_size, fp);
    int load_status = NO_ERRORS;

    map->width = UINT32_MAX;
    while (read != -1) {
        load_status = process_line(map, line, count);
        if (load_status != NO_ERRORS)
            return (load_status);
        count++;
        read = getline(&line, &line_size, fp);
    }
    map->nodes = realloc(map->nodes, (count + 1) * sizeof(node_t *));
    if (map->nodes == NULL)
        return (MALLOC_ERROR);
    map->nodes[count] = NULL;
    map->height = count;
    return (NO_ERRORS);
}

int stat_check(char *path)
{
    struct stat st_buf;

    if (stat(path, &st_buf) != 0)
        return (STAT_ERROR);
    if (S_ISDIR(st_buf.st_mode))
        return (IS_DIRECTORY_ERROR);
    return (NO_ERRORS);
}

int load_maze(char *map_path, maze_t *map)
{
    FILE *fp;
    char *line = NULL;
    int load_status = NO_ERRORS;
    uint32_t count = 0;

    load_status = stat_check(map_path);
    if (load_status != NO_ERRORS)
        return (load_status);
    fp = fopen(map_path, "r");
    map->nodes = malloc(sizeof(node_t *));
    if (map->nodes == NULL)
        return (MALLOC_ERROR);
    if (fp == NULL)
        return (INVALID_MAZE_ERROR);
    load_status = read_lines(map, line, count, fp);
    free(line);
    fclose(fp);
    if (map->height == 0 || map->width == 0)
        return (INVALID_MAZE_ERROR);
    return (load_status);
}
