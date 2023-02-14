/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** Function my_getnbr tetris
*/

#include "tetris.h"

int return_number_t(char const *str, int minus, int i)
{
    int nb = 0;

    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
        if (nb > 214748364)
            return 0;
        if (nb == 0)
            nb = str[i] - 48;
        else {
            nb *= 10;
            nb += (str[i] - 48);
        }
        i += 1;
    }
    if (minus % 2 == 1)
        nb *= -1;
    return nb;
}

int my_getnbr_t(char const *str)
{
    int i = 0;
    int minus = 0;
    int check = 0;

    if (!str || !str[0])
        return -1;
    if (!(str[0] >= '0' && str[0] <= '9'))
        return -1;
    for (int idx = 0; str[idx] != '\0'; idx += 1)
        if (str[idx] >= '0' && str[idx] <= '9')
            check += 1;
    if (check == 0)
        return -1;
    while (!(str[i] >= '0' && str[i] <= '9')) {
        if (str[i] == '-')
            minus += 1;
        i += 1;
    }
    return return_number_t(str, minus, i);
}
