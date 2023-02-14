/*
** EPITECH PROJECT, 2022
** load_map
** File description:
** load_map
*/

#include "tetris.h"

char *get_pattern_empty(int lenght_first_line)
{
    char *empty = malloc(sizeof(char) * lenght_first_line + 1);

    for (int i = 0; i < lenght_first_line; i++)
        empty[i] = '.';
    empty[lenght_first_line] = 'x';
    return empty;
}

char *define_string(game_t *game, int lenght_first_line, int nbr_rows)
{
    char *empty_pattern = get_pattern_empty(lenght_first_line);
    int max_height = game->data->max_height_tetrimino;
    char *string = malloc(sizeof(char) *
        ((nbr_rows + max_height) * lenght_first_line) + 1);

    for (int i = 0; i < max_height; i++)
        string = my_strcat(string, empty_pattern);
    free(empty_pattern);
    return string;
}

char *define_pattern(int lenght_first_line)
{
    char *pattern = malloc(sizeof(char) * lenght_first_line + 1);

    for (int i = 0; i < lenght_first_line; i++) {
        if (i == 0 || i == lenght_first_line - 1)
            pattern[i] = '|';
        else
            pattern[i] = ' ';
    }
    pattern[lenght_first_line] = 'x';
    return pattern;
}

char **make_map(int lenght_first_line, int nbr_rows, game_t *game)
{
    char **map = NULL;
    lenght_first_line += 2;
    char *string = define_string(game, lenght_first_line, nbr_rows);
    char *pattern = define_pattern(lenght_first_line);

    for (int i = 0; i < nbr_rows; i++)
        string = my_strcat(string, pattern);
    map = str_to_array(string, "xx");
    free(pattern);
    free(string);
    return map;
}
