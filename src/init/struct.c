/*
** EPITECH PROJECT, 2022
** Init Struct
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "tetris.h"

int check_space_first_tetrimino(game_t *game, int y, int x)
{
    int nbr_tetrimino = game->tetrimino_status->tetrimino_moving;
    char **tetrimino_moving = game->tetriminos[nbr_tetrimino]->pattern;
    int pos_x_default = game->map->nb_cols / 2;
    char **map = game->map->map;

    if (tetrimino_moving[y][x] != ' ')
        map[y][pos_x_default + x] = 58 + nbr_tetrimino;
    return 0;
}

int set_first_tetrimino(game_t *game)
{
    int nbr_tetrimino = game->tetrimino_status->tetrimino_moving;
    char **tetrimino_moving = game->tetriminos[nbr_tetrimino]->pattern;

    for (int y = 0; tetrimino_moving[y] != NULL; y++) {
        for (int x = 0; tetrimino_moving[y][x] != '\0'; x++) {
            check_space_first_tetrimino(game, y, x);
        }
    }
    return 0;
}

game_t *init_struct(const char **args)
{
    game_t *game = NULL;

    if (valid_tetriminos() <= 0)
        return NULL;
    if (!(game = malloc(sizeof(game_t))))
        return NULL;
    game->map = malloc(sizeof(map_t));
    game->map->nb_cols = 10;
    game->map->nb_lines = 20;
    if (init_tetriminos(game) == ERROR)
        return NULL;
    if (get_options(game, args) == ERROR)
        return NULL;
    if (init_data(game) == ERROR)
        return NULL;
    game->map->map = make_map(game->map->nb_cols, game->map->nb_lines, game);
    game->running_status = 1;
    set_first_tetrimino(game);
    return game;
}
