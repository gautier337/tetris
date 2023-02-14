/*
** EPITECH PROJECT, 2022
** my_free_arr
** File description:
** my_free_arr
*/

#include "my.h"

int my_free_arr(char **arr)
{
    if (!arr)
        return 84;
    for (int idx = 0; arr[idx] != NULL; idx += 1)
        free(arr[idx]);
    free(arr);
    return 0;
}
