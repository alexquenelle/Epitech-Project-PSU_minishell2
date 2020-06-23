/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_strcat_bis.c
*/

#include "my.h"

char *my_strcat_space(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    char *res = malloc(sizeof(char) * (dest_len + src_len) + 1);

    if (dest != NULL){
        for (i; dest[i] != '\0'; i = i + 1)
            res[i] = dest[i];
    }
    if (dest[0] != '\0'){
        res[i] = ' ';
        i = i + 1;
    }
    while (src[j] != '\0'){
        res[i] = src[j];
        i = i + 1;
        j = j + 1;
    }
    res[i] = '\0';
    return (res);
}

char *my_strcat_bis(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *res = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)) + 1);

    if (dest != NULL){
        for (i; dest[i] != '\0'; i = i + 1){
            res[i] = dest[i];
        }
    }
    res[i] = '=';
    i = i + 1;
    while (src[j] != '\0'){
        res[i] = src[j];
        i = i + 1;
        j = j + 1;
    }
    res[i] = '\0';
    return (res);
}