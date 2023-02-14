/*
** EPITECH PROJECT, 2022
** create_tetriminos
** File description:
** create_tetriminos
*/

#include "tetris.h"

int set_color_nbr_tetrimino(game_t *game, int y, int nbr_tetrimino,
    int pos_x_default)
{
    char **tetrimino_moving = game->tetriminos[nbr_tetrimino]->pattern;
    char **map = game->map->map;

    for (int x = 0; tetrimino_moving[y][x] != '\0'; x++)
        if (tetrimino_moving[y][x] != ' ')
            map[y][pos_x_default + x] = 58 + nbr_tetrimino;
    return 0;
}

int create_tetrimino(game_t *game)
{
    int nbr_tetrimino = rand() % (game->nb_valid_tetriminos) + 0;
    char **tetrimino_moving = game->tetriminos[nbr_tetrimino]->pattern;
    int pos_x_default = game->map->nb_cols / 2;

    for (int y = 0; tetrimino_moving[y] != NULL; y++)
        set_color_nbr_tetrimino(game, y, nbr_tetrimino, pos_x_default);
    return 0;
}
