/*
** EPITECH PROJECT, 2022
** Help File
** File description:
** Xavier VINCENT - Gautier BONHUR
*/

#include "tetris.h"

int print_help(const char *filename)
{
    char *help_msg = malloc(sizeof(char) * 1024);
    int fd = open(".help", O_RDONLY);

    if (!filename)
        return ERROR;
    if (fd == -1) {
        my_printf("Invalid Help File\n");
        free(help_msg);
        close(fd);
        return ERROR;
    }
    read(fd, help_msg, 1024);
    my_printf("Usage: %s [options]\n", filename);
    my_printf(help_msg);
    free(help_msg);
    close(fd);
    return SUCCESS;
}
