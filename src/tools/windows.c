/*
** EPITECH PROJECT, 2022
** Clear And Refresh
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "tetris.h"

int init_colors(game_t *game)
{
    if (!game)
        return ERROR;
    if (has_colors() == FALSE) {
        endwin();
        return my_puterror("Your terminal does not support color\n");
    }
    start_color();
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    wbkgdset(game->name_window, COLOR_PAIR(4));
    wbkgdset(game->score_window, COLOR_PAIR(4));
    wbkgdset(game->next_window, COLOR_PAIR(4));
    return SUCCESS;
}

int init_windows_size(game_t *game)
{
    int nb_lines = game->map->nb_lines;
    int nb_cols = game->map->nb_cols;
    int max_size = game->data->max_size_tetrimino;

    if (!game)
        return ERROR;
    if (max_size < 10)
        max_size = 10;
    game->map_window = newwin(nb_lines + 2, nb_cols + 2, 1, 1);
    game->name_window = newwin(5, 4 * max_size + 12, 1, nb_cols + 6);
    game->next_window = newwin(
        max_size + 5, 2 * max_size + 5, 6, nb_cols + 6);
    game->score_window = newwin(
        max_size + 5, 2 * max_size + 5, 6, nb_cols + 2 * max_size + 13);
    return SUCCESS;
}

int init_ncurses(game_t *game)
{
    if (!game)
        return ERROR;
    initscr();
    start_color();
    raw();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    if (init_windows_size(game) == ERROR)
        return ERROR;
    if (init_colors(game) == ERROR)
        return ERROR;
    return SUCCESS;
}

void clear_windows(game_t *game)
{
    if (!game)
        return;
    clear();
    wclear(game->map_window);
    wclear(game->name_window);
    wclear(game->score_window);
    wclear(game->next_window);
}

void refresh_windows(game_t *game)
{
    if (!game)
        return;
    refresh();
    wrefresh(game->map_window);
    wrefresh(game->name_window);
    wrefresh(game->score_window);
    wrefresh(game->next_window);
}
