/*
** EPITECH PROJECT, 2022
** init_map_size
** File description:
** init_map_size
*/

#include "tetris.h"

int get_map_col(game_t *game, const char *string)
{
    if (!game || !string)
        return ERROR;
    while (*string != ',' && *string != '\0')
        string++;
    if (*string == ',')
        string++;
    else
        return ERROR;
    if ((game->map->nb_cols = my_getnbr_t(string)) == -1)
        return ERROR;
    return SUCCESS;
}

int init_map_size(game_t *game, const char *string)
{
    char *manipulation_string = NULL;

    if (!game || !string)
        return ERROR;
    if (!(manipulation_string = my_strcpy(string)))
        return ERROR;
    while (*manipulation_string != '=' && *manipulation_string != '\0')
        manipulation_string++;
    if (*manipulation_string == '=')
        manipulation_string++;
    else
        return ERROR;
    if ((game->map->nb_lines = my_getnbr_t(manipulation_string)) == -1)
        return ERROR;
    if (get_map_col(game, manipulation_string) == ERROR)
        return ERROR;
    return SUCCESS;
}
