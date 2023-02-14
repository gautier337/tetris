/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "tetris.h"

int check_size(game_t *game)
{
    if (LINES < game->map->nb_lines + 1 || COLS < game->map->nb_cols) {
        mvprintw(LINES / 2, COLS / 2 - 12, "Please enlarge terminal.");
        return 0;
    }
    return 1;
}

int check_and_remove_full_line(game_t *game, int y)
{
    for (int x = 0; game->map->map[y][x] != '\0'; x += 1)
        if (game->map->map[y][x] == ' ')
            return SUCCESS;
    for (int x = 0; game->map->map[y][x] != '\0'; x += 1)
        game->map->map[y][x] = ' ';
    for (int idx = game->data->max_height_tetrimino; idx != y; idx += 1)
        for (int x = 0; game->map->map[idx][x] != '\0'; x += 1)
            game->map->map[idx][x] += (game->map->map[idx][x] >= '0' &&
                game->map->map[idx][x] <= '9') ? 10 : 0;
    game->data->score += 1;
    if (game->data->score % 10 == 0)
        game->data->current_level += 1;
    if (game->data->score > game->data->best_score)
        game->data->best_score = game->data->score;
    return SUCCESS;
}

int check_full_line_and_loose(game_t *game)
{
    int loose = 0;

    if (!game)
        return ERROR;
    for (int idx = 0; idx != game->data->max_height_tetrimino; idx += 1)
        for (int x = 0; game->map->map[idx][x] != '\0'; x += 1)
            loose += (game->map->map[idx][x] >= '0' &&
                game->map->map[idx][x] <= '9') ? 1 : 0;
    if (loose >= 1) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - 6, "You loose !");
        refresh();
        timeout(10000000);
        free_all(game);
        exit(SUCCESS);
    }
    for (int y = game->data->max_height_tetrimino;
        game->map->map[y] != NULL; y += 1)
        check_and_remove_full_line(game, y);
    return SUCCESS;
}

int run_game(game_t *game, int ch)
{
    int elapsed_time = game->data->end - game->data->start;

    if (!game)
        return ERROR;
    if (!check_size(game))
        return SUCCESS;
    check_event(game, ch);
    check_full_line_and_loose(game);
    if (elapsed_time >= 1) {
        game->data->timer += 1;
        usleep(10000);
    }
    if (elapsed_time >= 1) {
        down_tetriminos(game);
        usleep(300000 * 1 / game->data->current_level);
    }
    if (display_all(game) == ERROR)
        return ERROR;
    time(&game->data->end);
    return SUCCESS;
}

int tetris(const char **args)
{
    game_t *game = NULL;
    int ch = 0;

    if (!(game = init_struct(args)))
        return ERROR;
    if (game->options->debug == 1)
        return print_debug(game);
    if (init_ncurses(game) == ERROR)
        return ERROR;
    while (game->running_status != END && ch != game->options->keys->quit) {
        clear_windows(game);
        if (run_game(game, ch) == ERROR)
            return ERROR;
        refresh_windows(game);
        ch = getch();
    }
    free_all(game);
    if (game->running_status == ERROR)
        return ERROR;
    return SUCCESS;
}
