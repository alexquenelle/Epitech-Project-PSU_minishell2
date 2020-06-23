/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** .
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int k;

    k = 0;
    while (src[k] != '\0') {
        dest[k] = src[k];
        k = k + 1;
    }
    dest[k] = '\0';
    return (dest);
}
