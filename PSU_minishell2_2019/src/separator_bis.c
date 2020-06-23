/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** separator_bis.c
*/

#include "my.h"

char *cut_separator(char *str, int i)
{
    char *new_str = malloc(sizeof(char) * my_strlen(str));
    int j = 0;

    while (str[i] != '\0'){
        if (str[i] == ';')
            return (new_str);
        new_str[j] = str[i];
        j = j + 1;
        i = i + 1;
    }
    return (new_str);
}

int count_separator(char *str)
{
    int i = 0;
    int stock = 0;

    while (str[i] != '\0'){
        if (str[i] == ';')
            stock = stock + 1;
        i = i + 1;
    }
    return (stock);
}

char **fill_my_separator(char *first_cmd, char *second_cmd, char *str_stock)
{
    char *third_cmd = NULL;
    char *fourth_cmd = NULL;
    char **all_command = create_word_array(first_cmd, second_cmd);

    if (count_separator(str_stock) >= 2){
        third_cmd = cut_separator(str_stock,
        my_strlen(first_cmd) + my_strlen(second_cmd) + 2);
        all_command[2] = third_cmd;
        if (count_separator(str_stock) == 3){
            fourth_cmd = cut_separator(str_stock, my_strlen(first_cmd)
            + my_strlen(second_cmd) + my_strlen(third_cmd) + 3);
            all_command[3] = fourth_cmd;
        }
    }
    return (all_command);
}

char **create_word_array(char *first_cmd, char *second_cmd)
{
    char **all_command = malloc(sizeof(char *) * 3 + 1);
    all_command[0] = malloc(sizeof(char *) * 15);
    all_command[0] = first_cmd;
    all_command[1] = malloc(sizeof(char *) * 15);
    all_command[1] = second_cmd;
    all_command[2] = malloc(sizeof(char *) * 15);
    all_command[2] = NULL;
    all_command[3] = malloc(sizeof(char *) * 15);
    all_command[3] = NULL;

    return (all_command);
}