/*
** EPITECH PROJECT, 2022
** Init Data Game for Tetris
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "tetris.h"

int get_max_size_tetriminos(game_t *game)
{
    if (!game)
        return ERROR;
    game->data->max_width_tetrimino = 0;
    game->data->max_height_tetrimino = 0;
    for (int idx = 0; game->tetriminos[idx] != NULL; idx += 1) {
        if (game->tetriminos[idx]->width > game->data->max_width_tetrimino)
            game->data->max_width_tetrimino = game->tetriminos[idx]->width;
        if (game->tetriminos[idx]->height > game->data->max_height_tetrimino)
            game->data->max_height_tetrimino = game->tetriminos[idx]->height;
    }
    game->data->max_size_tetrimino =
        game->data->max_height_tetrimino >
        game->data->max_width_tetrimino ?
        game->data->max_height_tetrimino :
        game->data->max_width_tetrimino;
    return SUCCESS;
}

int tetrimino_status(game_t *game)
{
    game->tetrimino_status = malloc(sizeof(tetrimino_status_t));
    game->tetrimino_status->tetrimino_next =
        rand() % (game->nb_valid_tetriminos + 1);
    game->tetrimino_status->tetrimino_moving =
        rand() % (game->nb_valid_tetriminos + 1);
    return 0;
}

int init_data(game_t *game)
{
    if (!game)
        return ERROR;
    if (!(game->data = malloc(sizeof(data_t))))
        return ERROR;
    if (get_max_size_tetriminos(game) == ERROR)
        return ERROR;
    if (tetrimino_status(game) == ERROR)
        return ERROR;
    if ((game->data->best_score = get_value_from_file(
        DATA_BEST_SCORE_FILE)) == -1)
        game->data->best_score = 0;
    game->data->current_level = game->options->level;
    game->data->timer = 0;
    time(&game->data->start);
    return SUCCESS;
}
