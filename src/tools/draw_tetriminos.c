/*
** EPITECH PROJECT, 2022
** Draw Tetriminos for Tetris
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "tetris.h"

void draw_tetriminos(game_t *game, int y, int x)
{
    int max_height = game->data->max_height_tetrimino;

    if (game->map->map[y][x] >= '0' && game->map->map[y][x] <= '9') {
        wbkgdset(game->map_window, COLOR_PAIR(game->map->map[y][x] - '0'));
        mvwaddch(game->map_window, y + 1 - max_height, x, ACS_CKBOARD);
    } else if (game->map->map[y][x] >= '0' + 10 &&
        game->map->map[y][x] <= '9' + 10) {
        wbkgdset(game->map_window,
            COLOR_PAIR(game->map->map[y][x] - '0' - 10));
        mvwaddch(game->map_window, y + 1 - max_height, x, ACS_CKBOARD);
    } else
        mvwaddch(game->map_window, y + 1 - max_height, x, ' ');
}
