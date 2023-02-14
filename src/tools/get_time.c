/*
** EPITECH PROJECT, 2022
** Get Time Tools for Tetris
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "tetris.h"

char *put_time_in_str(int hour, int minute)
{
    char *time = NULL;
    char *str_hour = NULL;
    char *str_hour_long = NULL;
    char *str_minute = NULL;

    str_hour = my_put_nbr_in_str(hour);
    str_hour_long = my_strcat(str_hour, " : ");
    str_minute = my_put_nbr_in_str(minute);
    time = my_strcat(str_hour_long, str_minute);
    time[my_strlen(time)] = '\0';
    free(str_hour);
    free(str_hour_long);
    free(str_minute);
    return time;
}

char *get_time(game_t *game)
{
    int hour = 0;
    int minute = 0;
    char *time = NULL;

    hour = game->data->timer / 3600;
    minute = (game->data->timer - (3600 * hour)) / 60;
    time = put_time_in_str(hour, minute);
    return time;
}
