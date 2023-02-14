/*
** EPITECH PROJECT, 2022
** Check Tetrimino for Tetris
** File description:
** Xavier VINCENT - Max PEIXOTO
*/

#include "tetris.h"

int free_buff_arr(char **arr, char *buff)
{
    free(buff);
    free(arr);
    return 0;
}

int check_tetrimino_composition(char *tetrimino_file)
{
    int offset = 0;
    int count_back_slash_end = 0;

    if (!tetrimino_file)
        return ERROR;
    for (int i = 0; tetrimino_file[i] != '\0'; i++)
        if (tetrimino_file[i] == '\n')
            count_back_slash_end++;
    if (count_back_slash_end == 0)
        return ERROR;
    for (; tetrimino_file[offset] != '\n'; offset += 1);
    for (int idx = offset + 1; tetrimino_file[idx] != '\0'; idx += 1) {
        if (tetrimino_file[idx] != '*' && tetrimino_file[idx] != ' ' &&
            tetrimino_file[idx] != '\n')
            return ERROR;
    }
    return SUCCESS;
}

int check_size_tetrimino(char **arr, char *buff)
{
    char **arr_lines = NULL;
    int width = -1;
    int height = -1;
    int color_code = -1;

    if (!arr || !arr[0] || !arr[1] || !arr[2])
        return ERROR;
    height = my_getnbr_t(arr[0]);
    width = my_getnbr_t(arr[1]);
    color_code = my_getnbr_t(arr[2]);
    if (width <= 0 || height <= 0 || color_code < 0 || color_code > 7)
        return ERROR;
    if (!(arr_lines = str_to_array(buff, "\n\n")))
        return ERROR;
    if (my_arrlen(arr_lines) < 2 || !my_line_contains(arr_lines[1], '*')) {
        free(arr_lines);
        return ERROR;
    }
    free(arr_lines);
    return SUCCESS;
}

int check_tetrimino(const char *filepath)
{
    char *buff = NULL;
    char **arr = NULL;
    int stop = 0;

    if (!filepath)
        stop = 1;
    if (stop != 1 && my_strncmp_back(filepath, ".tetrimino", 10))
        stop = 1;
    if (stop != 1 && !(buff = my_load_file_in_mem(filepath)))
        stop = 1;
    if (stop != 1 && check_tetrimino_composition(buff) == ERROR)
        stop = 1;
    if (stop != 1 && !(arr = str_to_array(buff, "  ")))
        stop = 1;
    if (stop != 1 && check_size_tetrimino(arr, buff) == ERROR)
        stop = 1;
    free_buff_arr(arr, buff);
    if (stop == 1)
        return ERROR;
    return SUCCESS;
}
