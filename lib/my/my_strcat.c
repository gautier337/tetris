/*
** EPITECH PROJECT, 2022
** draw_text
** File description:
** my_runner
*/

#include "my.h"

char *my_strcat(char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    char *str3 = malloc(sizeof(char) *
        (my_strlen(str1) + my_strlen(str2) + 1));

    while (str1[i] != '\0') {
        str3[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0') {
        str3[i] = str2[j];
        i++;
        j++;
    }
    str3[i] = '\0';
    return str3;
}
