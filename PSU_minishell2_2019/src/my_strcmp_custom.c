/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_strcmp_custom.c
*/

#include "my.h"

int my_strcmp_custom(char *str1, char *str2)
{
    int i = 0;

    if (str1 == NULL && str2 == NULL)
        return (1);
    if (str1 == NULL)
        return (0);
    while (str1[i] != '=') {
        if (str1[i] != str2[i])
            return (0);
        i = i + 1;
    }
    return (1);
}