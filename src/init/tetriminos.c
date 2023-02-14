/*
** EPITECH PROJECT, 2022
** Init Tetriminos for Tetris
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "tetris.h"
#include <dirent.h>

int valid_tetriminos(void)
{
    struct dirent *dir;
    DIR *d = opendir("tetriminos/");
    int nbr_valid_tetriminos = 0;
    char *path = NULL;

    if (!d) {
        my_puterror("No folder tetriminos !\n");
        return -1;
    }
    while ((dir = readdir(d))) {
        path = my_strcat("tetriminos/", dir->d_name);
        if (dir->d_name[0] == '.' || check_tetrimino(path) == ERROR)
            continue;
        nbr_valid_tetriminos += 1;
    }
    free(dir);
    return nbr_valid_tetriminos;
}

tetrimino_t *load_tetrimino(const char *path)
{
    tetrimino_t *tetrimino = NULL;
    char *buff = my_load_file_in_mem(path);
    char **arr = str_to_array(buff, "  ");

    if (!path || !buff || !arr || !(tetrimino = malloc(sizeof(tetrimino_t))))
        return NULL;
    if ((tetrimino->width = my_getnbr_t(arr[0])) <= 0)
        return NULL;
    if ((tetrimino->height = my_getnbr_t(arr[1])) <= 0)
        return NULL;
    tetrimino->color = my_getnbr_t(arr[2]);
    free(arr);
    if (tetrimino->color < 0 || tetrimino->color > 7)
        return NULL;
    buff += my_getnbsize(tetrimino->width) + my_getnbsize(tetrimino->width) +
        my_getnbsize(tetrimino->color) + 3;
    tetrimino->pattern = str_to_array(buff, "\n\n");
    return tetrimino;
}

int init_tetriminos(game_t *game)
{
    struct dirent *dir;
    DIR *d = NULL;
    char *path = NULL;
    int idx = 0;

    if (!game)
        return ERROR;
    game->tetriminos = malloc(sizeof(tetrimino_t *) * valid_tetriminos() + 1);
    d = opendir("tetriminos/");
    while ((dir = readdir(d))) {
        path = my_strcat("tetriminos/", dir->d_name);
        if (dir->d_name[0] == '.' || check_tetrimino(path) == ERROR)
            continue;
        game->tetriminos[idx] = load_tetrimino(path);
        idx += 1;
    }
    closedir(d);
    free(dir);
    game->tetriminos[(game->nb_valid_tetriminos = valid_tetriminos())] = NULL;
    return SUCCESS;
}
