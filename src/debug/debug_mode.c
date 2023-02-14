/*
** EPITECH PROJECT, 2022
** debug
** File description:
** debug_mode
*/

#include "tetris.h"
#include <dirent.h>

int print_keys(game_t *game)
{
    keys_t *keys = game->options->keys;

    my_printf("Key left: %s (%d)\n", keyname(keys->left), keys->left);
    my_printf("Key right: %s (%d)\n", keyname(keys->right), keys->right);
    my_printf("Key turn: %s (%d)\n", keyname(keys->turn), keys->turn);
    my_printf("Key drop: %s (%d)\n", keyname(keys->drop), keys->drop);
    my_printf("Key quit: %s (%d)\n", keyname(keys->quit), keys->quit);
    my_printf("Key pause: %s (%d)\n", keyname(keys->pause), keys->pause);
    return SUCCESS;
}

int print_settings(game_t *game)
{
    if (game->options->next == 1)
        my_printf("Next: No\n");
    else
        my_printf("Next: Yes\n");
    my_printf("Level: %d\n", game->options->level);
    my_printf("Size: %d*%d\n", game->map->nb_lines, game->map->nb_cols);
    return SUCCESS;
}

int print_tetriminos(void)
{
    struct dirent *dir;
    DIR *d = opendir("tetriminos/");
    int nbr_tetriminos = 0;
    int nbr_error = 0;

    if (!d)
        return ERROR;
    while ((dir = readdir(d))) {
        if (dir->d_name[0] == '.' ||
            check_tetrimino(my_strcat("tetriminos/", dir->d_name)) == ERROR)
            continue;
        nbr_tetriminos++;
        nbr_error = display_tetrimino(dir->d_name, nbr_error);
    }
    if (nbr_error == get_nbr_tetriminos())
        return ERROR;
    closedir(d);
    free(dir);
    return SUCCESS;
}

int print_debug(game_t *game)
{
    if (check_same_keys(game) == 84) {
        my_putstr("Error: a key is assigned to two actions.\n");
        return ERROR;
    }
    print_keys(game);
    print_settings(game);
    my_printf("\nNumber of tetriminos: %d\n", get_nbr_tetriminos());
    if (print_tetriminos() == 84) {
        my_putstr("Error: in folder tetriminos.\n");
        return ERROR;
    }
    return SUCCESS;
}
