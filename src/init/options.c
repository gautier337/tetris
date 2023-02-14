/*
** EPITECH PROJECT, 2022
** Init Key Bindongs for Tetris
** File description:
** Xavier VINCENT -  Gautier BONHUR
*/

#include "tetris.h"

int check_options(game_t *game)
{
    keys_t *keys = game->options->keys;

    if (!game)
        return ERROR;
    if (game->options->level == -1)
        return my_puterror("Invalid Level\n");
    if (keys->left == -1 || keys->left > 347)
        return my_puterror("Invalid Key Left\n");
    if (keys->right == -1 || keys->right > 347)
        return my_puterror("Invalid Key Right\n");
    if (keys->turn == -1 || keys->turn > 347)
        return my_puterror("Invalid Key Turn\n");
    if (keys->drop == -1 || keys->drop > 347)
        return my_puterror("Invalid Key Drop\n");
    if (keys->pause == -1 || keys->pause > 347)
        return my_puterror("Invalid Key Pause\n");
    if (keys->quit == -1 || keys->quit > 347)
        return my_puterror("Invalid Key Quit\n");
    return SUCCESS;
}

int get_other_options_2(game_t *game, const char **args)
{
    int error = SUCCESS;

    if (!game || !args)
        return ERROR;
    for (int idx = 0; args[idx] != NULL; idx += 1) {
    if (!my_strncmp(args[idx], "--debug", 7) ||
            !my_strncmp(args[idx], "-D", 2))
            game->options->debug = 1;
        if (!my_strncmp(args[idx], "--map-size", 10))
            error = init_map_size(game, args[idx]);
    }
    if (error == ERROR ||
        game->map->nb_cols < 3 ||
        game->map->nb_lines < 3)
        return my_puterror("Invalid Maps Size\n");
    return SUCCESS;
}

int get_other_options(game_t *game, const char **args)
{
    if (!game || !args)
        return ERROR;
    for (int idx = 0; args[idx] != NULL; idx += 1) {
        if (!my_strncmp(args[idx], "--level=", 9)) {
            args[idx] += 8;
            game->options->level = my_getnbr_t(args[idx]);
        }
        if (!my_strncmp(args[idx], "-L", 2))
            game->options->level = my_getnbr_t(args[idx + 1]);
        if (!my_strncmp(args[idx], "--without-next", 14) ||
            !my_strncmp(args[idx], "-w", 2))
            game->options->next = 1;
    }
    return get_other_options_2(game, args);
}

int init_options(game_t *game)
{
    if (!game)
        return ERROR;
    if (!(game->options = malloc(sizeof(options_t))))
        return ERROR;
    if (!(game->options->keys = malloc(sizeof(keys_t))))
        return ERROR;
    game->options->level = 1;
    game->options->keys->left = KEY_LEFT;
    game->options->keys->right = KEY_RIGHT;
    game->options->keys->turn = KEY_UP;
    game->options->keys->drop = KEY_DOWN;
    game->options->keys->quit = 'q';
    game->options->keys->pause = ' ';
    game->options->next = 0;
    game->options->debug = 0;
    return 0;
}

int get_options(game_t *game, const char **args)
{
    if (!game || !args)
        return ERROR;
    if (init_options(game) == ERROR)
        return ERROR;
    if (get_key_bindings(game, args) == ERROR)
        return ERROR;
    if (get_other_options(game, args) == ERROR)
        return ERROR;
    if (check_options(game) == ERROR)
        return ERROR;
    return SUCCESS;
}
