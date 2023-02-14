/*
** EPITECH PROJECT, 2022
** my_line_contains
** File description:
** Xavier VINCENT
*/

#include "my.h"

int my_line_contains(char *line, char c)
{
    if (!line)
        return 84;
    for (int idx = 0; line[idx] != '\0'; idx += 1)
        if (line[idx] == c)
            return 1;
    return 0;
}
