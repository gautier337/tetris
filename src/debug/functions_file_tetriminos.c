/*
** EPITECH PROJECT, 2022
** get_nbr_tetriminos
** File description:
** get_nbr_tetriminos
*/

#include "tetris.h"
#include <dirent.h>
#include <stdio.h>

int get_nbr_tetriminos(void)
{
    struct dirent *dir;
    DIR *d = opendir("tetriminos/");
    int nbr_tetriminos = 0;

    if (!d)
        return my_puterror("Error: There isn't folder tetriminos/\n");
    while ((dir = readdir(d))) {
        if (dir->d_name[0] == '.')
            continue;
        nbr_tetriminos++;
    }
    free(dir);
    closedir(d);
    return nbr_tetriminos;
}

int get_nbr_spaces_tetrimino(char *line_tetrimino)
{
    int nbr_spaces_at_end = 0;
    int idx = 0;

    for (; line_tetrimino[idx] != '\0'; idx++) {
        if (line_tetrimino[idx] == ' ')
            nbr_spaces_at_end++;
        else
            nbr_spaces_at_end = 0;
    }
    if (nbr_spaces_at_end > 0)
        return idx - nbr_spaces_at_end;
    return 0;
}

int print_line_tetrimino(char **new_word_array)
{
    int nbr_to_putchar = 0;

    for (int i = 1; new_word_array[i] != NULL; i++) {
        nbr_to_putchar = get_nbr_spaces_tetrimino(new_word_array[i]);
        if (nbr_to_putchar == 0) {
            my_putstr(new_word_array[i]);
            my_putchar('\n');
            continue;
        }
        for (int idx = 0; idx < nbr_to_putchar; idx++)
            my_putchar(new_word_array[i][idx]);
        my_putchar('\n');
    }
    return 0;
}

int print_cat_tetriminos(const char *filepath, char *name)
{
    char *buff = my_load_file_in_mem(filepath);
    char **arr = str_to_array(buff, "  ");
    char **new_word_array = NULL;

    if (!buff || !arr)
        return ERROR;
    name[my_strlen(name) - 10] = '\0';
    my_printf("Tetriminos '%s': size %d*%d, color %d\n", name,
        my_getnbr(arr[0]), my_getnbr(arr[1]), my_getnbr(arr[2]));
    new_word_array = str_to_array(buff, "\n\n");
    print_line_tetrimino(new_word_array);
    return 0;
}

int display_tetrimino(char *filepath, int nbr_error)
{
    char *tetrimino_path = NULL;

    if (!filepath || !(tetrimino_path = my_strcat("tetriminos/", filepath)))
        return ERROR;
    if (check_tetrimino(tetrimino_path) == ERROR) {
        if (my_strlen(filepath) > 10)
            filepath[my_strlen(filepath) - 10] = '\0';
        my_printf("Tetriminos '%s': error\n", filepath);
        nbr_error++;
    } else
        print_cat_tetriminos(tetrimino_path, filepath);
    return nbr_error;
}
