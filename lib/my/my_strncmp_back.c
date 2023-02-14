/*
** EPITECH PROJECT, 2022
** My Strncmp_back
** File description:
** Xavier VINCENT
*/

#include "my.h"

int my_strncmp_back(char const *s1, char const *s2, int n)
{
    int i = my_strlen(s1);
    int i2 = my_strlen(s2);
    int idx = 0;
    int tmp = 0;

    if (!s1 || !s2)
        return 84;
    while (i != 0 && i2 != 0 && s1[i] == s2[i2] && (idx < n)) {
        i -= 1;
        i2 -= 1;
        idx += 1;
    }
    tmp = s1[i] - s2[i2];
    if (tmp > 0)
        return 1;
    else if (tmp < 0)
        return -1;
    else
        return 0;
}
