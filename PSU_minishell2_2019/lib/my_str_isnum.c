/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** .
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int x = 0;

    while (str[x] != '\0'){
        if ((str[x] > '9' || str[x] < '0') &&
        str[x] != '\0' && str[x] != '\n')
        return (1);
        x++;
    }
    return (0);

}