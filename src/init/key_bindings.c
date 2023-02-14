/*
** EPITECH PROJECT, 2022
** Init Key Bindings for Tetris
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "tetris.h"

int get_key_bindings_3(game_t *game, const char **args)
{
    keys_t *keys = NULL;

    if (!game || !args)
        return ERROR;
    keys = game->options->keys;
    for (int idx = 0; args[idx] != NULL; idx += 1) {
        if (!my_strncmp(args[idx], "--key-quit=", 11)) {
            args[idx] += 11;
            keys->quit = my_getnbr_t(args[idx]);
        }
        if (!my_strncmp(args[idx], "--key-pause=", 12)) {
            args[idx] += 12;
            keys->pause = my_getnbr_t(args[idx]);
        }
        if (!my_strncmp(args[idx], "-q", 2))
            keys->quit = my_getnbr_t(args[idx + 1]);
        if (!my_strncmp(args[idx], "-p", 2))
            keys->pause = my_getnbr_t(args[idx + 1]);
    }
    return SUCCESS;
}

int get_key_bindings_2(game_t *game, const char **args)
{
    keys_t *keys = NULL;

    if (!game || !args)
        return ERROR;
    keys = game->options->keys;
    for (int idx = 0; args[idx] != NULL; idx += 1) {
        if (!my_strncmp(args[idx], "--key-turn=", 11)) {
            args[idx] += 11;
            keys->turn = my_getnbr_t(args[idx]);
        }
        if (!my_strncmp(args[idx], "-t", 2))
            keys->turn = my_getnbr_t(args[idx + 1]);
        if (!my_strncmp(args[idx], "--key-drop=", 11)) {
            args[idx] += 11;
            keys->drop = my_getnbr_t(args[idx]);
        }
        if (!my_strncmp(args[idx], "-d", 2))
            keys->drop = my_getnbr_t(args[idx + 1]);
    }
    return get_key_bindings_3(game, args);
}

int get_key_bindings(game_t *game, const char **args)
{
    keys_t *keys = NULL;

    if (!game || !args)
        return ERROR;
    keys = game->options->keys;
    for (int idx = 0; args[idx] != NULL; idx += 1) {
        if (!my_strncmp(args[idx], "--key-left=", 11)) {
            args[idx] += 11;
            keys->left = my_getnbr_t(args[idx]);
        }
        if (!my_strncmp(args[idx], "-l", 2))
            keys->left = my_getnbr_t(args[idx + 1]);
        if (!my_strncmp(args[idx], "--key-right=", 12)) {
            args[idx] += 12;
            keys->right = my_getnbr_t(args[idx]);
        }
        if (!my_strncmp(args[idx], "-r", 2))
            keys->right = my_getnbr_t(args[idx + 1]);
    }
    return get_key_bindings_2(game, args);
}
