/*
** EPITECH PROJECT, 2022
** reset_moving
** File description:
** reset_moving
*/

#include "tetris.h"

int reset_map(char **map, int y, int x)
{
    if (map[y][x] != '|' && map[y][x] != '.' && map[y][x] != ' '
        && !(map[y][x] >= '0' && map[y][x] <= '9')) {
        map[y][x] -= 10;
    }
    return 0;
}

void reset_moving_status(char **map)
{
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            reset_map(map, y, x);
        }
    }
}
