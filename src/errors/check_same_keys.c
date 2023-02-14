/*
** EPITECH PROJECT, 2022
** check_same_keys
** File description:
** check_same_keys
*/

#include "tetris.h"

int check_same_keys_two(game_t *game)
{
    keys_t *keys = game->options->keys;

    if (keys->drop == keys->left || keys->drop == keys->right
        || keys->drop == keys->turn
        || keys->drop == keys->quit || keys->drop == keys->pause)
        return 84;
    if (keys->quit == keys->left || keys->quit == keys->right
        || keys->quit == keys->turn
        || keys->quit == keys->drop || keys->quit == keys->pause)
        return 84;
    if (keys->pause == keys->left || keys->pause == keys->right
        || keys->pause == keys->turn
        || keys->pause == keys->drop || keys->pause == keys->quit)
        return 84;
    return 0;
}

int check_same_keys(game_t *game)
{
    keys_t *keys = game->options->keys;

    if (keys->left == keys->right || keys->left == keys->turn
        || keys->left == keys->drop
        || keys->left == keys->quit || keys->left == keys->pause)
        return 84;
    if (keys->right == keys->left || keys->right == keys->turn
        || keys->right == keys->drop
        || keys->right == keys->quit || keys->right == keys->pause)
        return 84;
    if (keys->turn == keys->left || keys->turn == keys->right
        || keys->turn == keys->drop
        || keys->turn == keys->quit || keys->turn == keys->pause)
        return 84;
    return check_same_keys_two(game);
}
