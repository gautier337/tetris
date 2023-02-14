/*
** EPITECH PROJECT, 2022
** Main for Tetris
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "tetris.h"
#include <dirent.h>

int check_bytes_error(void)
{
    struct dirent *dir_test_struct;
    DIR *directory = opendir("tetriminos/");
    char *filepath_tetri = NULL;
    struct stat t;

    if (!directory) {
        my_putstr("No folder tetriminos !\n");
        return -1;
    }
    while ((dir_test_struct = readdir(directory))) {
        if (dir_test_struct->d_name[0] == '.')
            continue;
        filepath_tetri = my_strcat("tetriminos/", dir_test_struct->d_name);
        stat(filepath_tetri, &t);
        if (t.st_size > 28)
            return -1;
    }
    closedir(directory);
    free(dir_test_struct);
    return 0;
}

int check_helper_params(const char **argv)
{
    for (int idx = 0; argv[idx] != NULL; idx++)
        if (!my_strncmp(argv[idx], "--help", 6))
            return 1;
    return 0;
}

int main(int argc, const char **argv)
{
    argc -= 1;
    if (!argv)
        return ERROR;
    if (check_bytes_error() == -1)
        return ERROR;
    if (check_helper_params(argv))
        return print_help(argv[0]);
    return tetris(argv);
}
