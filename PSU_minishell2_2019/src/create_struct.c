/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** create_struct.c
*/

#include "my.h"

myshell *create_struct(char **env)
{
    myshell *name_var = malloc(sizeof(myshell));
    int y = nbr_line_of_env(env);
    name_var->my_newenv = malloc(sizeof(char *) * y + 1);
    name_var->old_pwd = get_old_pwd(env);
    name_var->a = 0;
    name_var->pwd_to_change = 0;
    name_var->pwd_to_display = NULL;
    int line_y = 0;

    while (line_y != y) {
            name_var->my_newenv[line_y] = malloc(sizeof(char *) *
            my_strlen(env[line_y]));
            my_strcpy(name_var->my_newenv[line_y], env[line_y]);
            line_y = line_y + 1;
        }
    name_var->my_newenv[line_y] = NULL;
    return (name_var);
}