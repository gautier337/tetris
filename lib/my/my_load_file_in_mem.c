/*
** EPITECH PROJECT, 2022
** My Load File in Mem
** File description:
** Xavier VINCENT - Hugo DUBOIS
*/

#include "my.h"

char *my_load_file_in_mem(const char *file)
{
    struct stat st;
    int fd = 0;
    char *buff = NULL;

    if (!file)
        return NULL;
    if ((fd = open(file, O_RDONLY)) == -1)
        return NULL;
    if (stat(file, &st) == -1)
        return NULL;
    if (st.st_size <= 0)
        return NULL;
    if ((buff = malloc(sizeof(char) * st.st_size + 1)) == NULL)
        return NULL;
    if (read(fd, buff, st.st_size) < st.st_size)
        return NULL;
    buff[my_strlen(buff) + 1] = '\0';
    close(fd);
    return buff;
}
