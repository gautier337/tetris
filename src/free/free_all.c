/*
** EPITECH PROJECT, 2022
** free_all
** File description:
** free_all
*/

#include "tetris.h"

void free_tab(char **tab)
{
    if (!tab)
        return;
    for (int i = 0; tab[i] != NULL; i += 1)
        free(tab[i]);
    free(tab);
}

int free_all(game_t *game)
{
    save_value_in_file(game->data->best_score, DATA_BEST_SCORE_FILE);
    delwin(game->map_window);
    delwin(game->score_window);
    endwin();
    free_tab(game->map->map);
    free(game->map);
    free(game->options->keys);
    free(game->options);
    for (int i = 0; game->tetriminos[i] != NULL; i++) {
        free_tab(game->tetriminos[i]->pattern);
        free(game->tetriminos[i]);
    }
    free(game->tetrimino_status);
    return 0;
}
