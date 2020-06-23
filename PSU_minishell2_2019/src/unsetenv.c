/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** unsetenv.c
*/

#include "my.h"

char **my_unsetenv(char *buffer, myshell *stock)
{
    char **buf_env = shell_str_to_array(buffer);
    char *str_stock = format_str(buf_env);
    buf_env = shell_str_to_array(str_stock);

    if (buf_env[1] == NULL)
        my_printf("Too few arguments.\n");
    else if (check_elem_line_y(buf_env[1], stock) != -1){
        stock->my_newenv = remove_elem(stock->my_newenv, buf_env[1], stock);
    }
}

char **remove_elem(char **env, char *str, myshell *stock)
{
    int y = nbr_line_of_env(env);
    char **my_newenv = malloc(sizeof(char *) * y + 1);
    int value = check_elem_line_y(str, stock);
    int i = 0;
    int line_y = 0;

    while (env[line_y] != NULL){
        if (value == i)
            line_y = line_y + 1;
        if (env[line_y] == NULL)
            return (my_newenv);
        my_newenv[i] = malloc(sizeof(char *) * my_strlen(env[line_y]));
        my_strcpy(my_newenv[i], env[line_y]);
        line_y = line_y + 1;
        i = i + 1;
    }
    my_newenv[line_y + 1] = NULL;
    return (my_newenv);
}