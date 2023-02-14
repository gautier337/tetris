/*
** EPITECH PROJECT, 2022
** Save Data for Tetris
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "tetris.h"

void save_value_in_file(int value, const char filepath[])
{
    FILE *fp = fopen(filepath, "wb");
    char *str_value = my_put_nbr_in_str(value);
    size_t error = -1;

    if (!fp)
        return;
    if (fwrite(str_value, 1, my_strlen(str_value), fp) == error)
        return;
    free(str_value);
    fclose(fp);
}

int get_value_from_file(const char path[])
{
    FILE *fp = fopen(path, "rb");
    int value = 0;
    char *value_str = malloc(sizeof(char) * 100);
    size_t error = -1;

    if (!fp)
        return -1;
    if (fread(value_str, 1, 100, fp) == error)
        return -1;
    value = my_getnbr(value_str);
    free(value_str);
    fclose(fp);
    return value;
}
