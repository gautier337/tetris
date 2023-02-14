/*
** EPITECH PROJECT, 2022
** Dispay Game for Tetris
** File description:
** Display Map
*/

#include "tetris.h"

int display_all(game_t *game)
{
    const char *timer = get_time(game);

    if (!game)
        return ERROR;
    if (draw_window_map(game) == ERROR)
        return ERROR;
    if (draw_window_name(game) == ERROR)
        return ERROR;
    if (draw_window_next(game) == ERROR)
        return ERROR;
    if (draw_window_score(game) == ERROR)
        return ERROR;
    mvwprintw(game->score_window, getmaxy(
        game->score_window) - 3, 2, "Timer");
    mvwprintw(game->score_window, getmaxy(game->score_window) - 2,
        getmaxx(game->score_window) - my_strlen(timer) - 3, timer);
    free(timer);
    return SUCCESS;
}
