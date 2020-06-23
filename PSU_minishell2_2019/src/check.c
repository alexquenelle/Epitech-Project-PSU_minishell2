/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** print_env.c
*/

#include "my.h"

int print_myenv(myshell *stock)
{
    int line_y = 0;
    int y = nbr_line_of_env(stock->my_newenv);

    while (stock->my_newenv[line_y] != NULL) {
            my_printf("%s\n", stock->my_newenv[line_y]);
        line_y = line_y + 1;
    }
}

char **insert_elem(char **env, char *str)
{
    int y = nbr_line_of_env(env);
    char **my_newenv = malloc(sizeof(char *) * y + 1);
    int line_y = 0;

    while (env[line_y] != NULL) {
            my_newenv[line_y] = malloc(sizeof(char *) * my_strlen(env[line_y]));
            my_strcpy(my_newenv[line_y], env[line_y]);
            line_y = line_y + 1;
    }
    my_newenv[line_y ] = malloc(sizeof(char *) * my_strlen(str) + 1);
    my_strcpy(my_newenv[line_y ], str);
    my_newenv[line_y + 1] = NULL;
    return (my_newenv);
}

int check_elem(char *str, myshell *stock)
{
    int line_y = 0;

    while (stock->my_newenv[line_y] != NULL) {
        if (my_strcmp_custom(stock->my_newenv[line_y], str) == 1)
            return (1);
        line_y = line_y + 1;
    }
    return (2);
}

int check_elem_line_y(char *str, myshell *stock)
{
    int line_y = 0;

    while (stock->my_newenv[line_y] != NULL) {
        if (my_strcmp_custom(stock->my_newenv[line_y], str) == 1)
            return (line_y);
        line_y = line_y + 1;
    }
    return (-1);
}

char **insert_elem_bis(char **env, char *str)
{
    int y = nbr_line_of_env(env);
    char **my_newenv = malloc(sizeof(char *) * y + 1);
    int line_y = 0;

    while (env[line_y] != NULL) {
            my_newenv[line_y] = malloc(sizeof(char *) * my_strlen(env[line_y]));
            my_strcpy(my_newenv[line_y], env[line_y]);
            line_y = line_y + 1;
    }
    my_newenv[line_y ] = malloc(sizeof(char *) * my_strlen(str) + 1);
    my_strcpy(my_newenv[line_y ], str);
    my_newenv[line_y + 1] = NULL;
    return (my_newenv);
}