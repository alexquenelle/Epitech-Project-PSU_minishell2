/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** .
*/

#include "my.h"

int my_char_isalphanumeric(char letter)
{
    if (letter >= 'a' && letter <= 'z' || letter >= 'A' && letter <= 'Z')
        return (1);
    else
        return (0);
}

int my_str_isalphanumeric(char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
            i = i + 1;
        else
            return (0);
    }
    return (1);
}