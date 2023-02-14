/*
** EPITECH PROJECT, 2022
** check_left_right
** File description:
** check_movement_sides
*/

#include "tetris.h"

void change_the_map(char **map, int y, int change)
{
    for (int x = 1; change == -1 && map[y][x] != '\0'; x++) {
        if (map[y][x] != ' ' && map[y][x] != '.' && map[y][x] != '|'
            && (map[y][x] > '9') && map[y][x + change] != '|'
            && map[y][x + change] != '.') {
            map[y][x + change] = map[y][x];
            map[y][x] = ' ';
        }
    }
    for (int x = my_strlen(map[0]) - 1;
        change != -1 && map[y][x] != '\0'; x--) {
        if (map[y][x] != ' ' && map[y][x] != '.' && map[y][x] != '|'
            && (map[y][x] > '9') && map[y][x + change] != '|'
            && map[y][x + change] != '.') {
            map[y][x + change] = map[y][x];
            map[y][x] = ' ';
        }
    }
}

void move_to_a_side(game_t *game, int right_or_left)
{
    char **map = game->map->map;
    int change = 0;

    if (right_or_left == 1)
        change = -1;
    else
        change = 1;
    for (int y = 0; map[y] != NULL; y++) {
        change_the_map(map, y, change);
    }
}

int return_check_if_can_move(char **map, int change, int y)
{
    for (int x = 1; map[y][x] != '\0'; x++) {
        if (map[y][x] != ' ' && map[y][x] != '.' && map[y][x] != '|'
            && (map[y][x] > '9')
            && ((map[y][x + change] >= '0' && map[y][x + change] <= '9')
            || map[y][x + change] == '|' || map[y][x + change] == '.')) {
            return 0;
        }
    }
    return 1;
}

int check_if_can_move(game_t *game, int right_or_left)
{
    char **map = game->map->map;
    int change = 0;

    if (right_or_left == 1)
        change = -1;
    else
        change = 1;
    for (int y = 0; map[y] != NULL; y++)
        if (return_check_if_can_move(map, change, y) == 0)
            return 0;
    return 1;
}

int check_sides_move(game_t *game, int right_or_left)
{
    if (right_or_left == 1 && check_if_can_move(game, 1) == 1)
        move_to_a_side(game, 1);
    if (right_or_left == 0 && check_if_can_move(game, 0) == 1)
        move_to_a_side(game, 0);
    return 0;
}
