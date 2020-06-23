/*
** EPITECH PROJECT, 2019
** STRTO
** File description:
** gcg.c
*/

#include<stdlib.h>

int copy_char(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
    || (c >= '0' && c <= '9')) {
        return (1);
    } else if (c == '/' || c == '-' || c == '_' || c == '.'
    || c == 61 || c == '|' || c == ';') {
        return (1);
    } else {
        return (0);
    }
}

int my_strlen_str_array(char *str)
{
    int i = 0;
    int n = 0;

    while (str[i] != '\0')
    {
        if (copy_char(str[i]) == 1)
            n += 1;
        i += 1;
    }
    return (n);
}

int my_strlen_words(char *str, int i)
{
    int n = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == ':')
            return (n);
        i += 1;
        n += 1;
    }
    return (n);
}

char **shell_str_to_array_space(int y, int n, int x, char *str)
{
    char **buffer = malloc(sizeof(char *) * my_strlen_str_array(str) + 1);
    int i = 0;

    while (n < my_strlen_str_array(str) && str[i]) {
        if (copy_char(str[i]) == 1){
            buffer[y] = malloc(sizeof(char *) * my_strlen_words(str, i) + 1);
            while (copy_char(str[i]) == 1) {
                buffer[y][x] = str[i];
                x += 1;
                i += 1;
                n += 1;
            }
        buffer[y][x] = '\0';
        y += 1;
        }
        x = 0;
        i += 1;
    }
    buffer[y] = NULL;
    return (buffer);
}

char **shell_str_to_array(char *str)
{
    char **buffer = malloc(sizeof(char *) * my_strlen_str_array(str) + 1);
    int i = 0;
    int y = 0;
    int n = 0;
    int x = 0;

    buffer = shell_str_to_array_space(y, n, x, str);
    return (buffer);
}