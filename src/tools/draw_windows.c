/*
** EPITECH PROJECT, 2022
** Draw Windows for Tetris
** File description:
** Xavier VINENT - Gautier BONHUR
*/

#include "tetris.h"

void draw_window_borders(WINDOW *window)
{
    int x = 0;
    int y = 0;

    if (!window)
        return;
    getmaxyx(window, y, x);
    mvwaddch(window, 0, 0, ACS_ULCORNER);
    mvwaddch(window, y - 1, 0, ACS_LLCORNER);
    mvwaddch(window, 0, x - 1, ACS_URCORNER);
    mvwaddch(window, y - 1, x - 1, ACS_LRCORNER);
    for (int idx = 1; idx < (y - 1); idx += 1) {
        mvwaddch(window, idx, 0, ACS_VLINE);
        mvwaddch(window, idx, x - 1, ACS_VLINE);
    }
    for (int idx = 1; idx < (x - 1); idx += 1) {
        mvwaddch(window, 0, idx, ACS_HLINE);
        mvwaddch(window, y - 1, idx, ACS_HLINE);
    }
}

int draw_window_map(game_t *game)
{
    if (!game)
        return ERROR;
    draw_window_borders(game->map_window);
    for (int y = game->data->max_height_tetrimino; game->map->map[y] != NULL;
        y += 1)
        for (int x = 1; game->map->map[y][x + 1] != '\0'; x += 1)
            draw_tetriminos(game, y, x);
    return SUCCESS;
}

int draw_window_name(game_t *game)
{
    if (!game)
        return ERROR;
    draw_window_borders(game->name_window);
    mvwprintw(game->name_window,
        getmaxy(game->name_window) / 2,
        getmaxx(game->name_window) / 2 - 3, "TETRIS");
    return SUCCESS;
}

int draw_window_next(game_t *game)
{
    if (!game)
        return ERROR;
    draw_window_borders(game->next_window);
    mvwprintw(game->next_window, 1, 2, "Next");
    return SUCCESS;
}

int draw_window_score(game_t *game)
{
    WINDOW *window = game->score_window;
    char *score = my_put_nbr_in_str(game->data->score);
    char *best_score = my_put_nbr_in_str(game->data->best_score);
    char *level = my_put_nbr_in_str(game->data->current_level);

    if (!game)
        return ERROR;
    draw_window_borders(window);
    mvwprintw(window, 1, 2, "Score");
    mvwprintw(window, 2, getmaxx(window) - my_strlen(score) - 3, score);
    mvwprintw(window, 4, 2, "Best Score");
    mvwprintw(
        window, 5, getmaxx(window) - my_strlen(best_score) - 3, best_score);
    mvwprintw(window, getmaxy(window) / 2 + 2, 2, "Level");
    mvwprintw(window, getmaxy(window) / 2 + 3,
        getmaxx(window) - my_strlen(level) - 3, level);
    free(score);
    free(best_score);
    free(level);
    return SUCCESS;
}
