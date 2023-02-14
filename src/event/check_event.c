/*
** EPITECH PROJECT, 2022
** check_event
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "tetris.h"

int check_colision(char **map, int y, int x)
{
    if ((map[y][x] >= '0' && map[y][x] <= '9'))
        return 0;
    if (map[y][x] != ' ' && map[y][x] != '.' && map[y][x] != '|') {
        if (map[y + 1] == NULL ||
            (map[y + 1][x] >= '0' && map[y + 1][x] <= '9')) {
            reset_moving_status(map);
            return 1;
        }
    }
    return 0;
}

void edit_map(char **map, int y, int x, game_t *game)
{
    char tmp = 0;

    if (check_colision(map, y, x) == 1)
        create_tetrimino(game);
    if (map[y + 1] != NULL &&
        !(map[y][x] >= '0' && map[y][x] <= '9') &&
        !(map[y + 1][x] >= '0' && map[y + 1][x] <= '9')
        && map[y][x] != ' ' && map[y][x] != '.'
        && map[y][x] != '|') {
        tmp = map[y + 1][x];
        map[y + 1][x] = map[y][x];
        map[y][x] = tmp;
    }
    return;
}

void down_tetriminos(game_t *game)
{
    char **map = game->map->map;
    int y = game->map->nb_lines +
        game->data->max_height_tetrimino - 1;

    for (; y != -1; y--) {
        for (int x = 1; map[y][x + 1] != '\0'; x++) {
            edit_map(map, y, x, game);
        }
    }
    return;
}

void check_event(game_t *game, int ch)
{
    keys_t *keys = game->options->keys;

    if (ch == keys->drop)
        down_tetriminos(game);
    if (ch == keys->right)
        check_sides_move(game, 0);
    if (ch == keys->left)
        check_sides_move(game, 1);
    return;
}
