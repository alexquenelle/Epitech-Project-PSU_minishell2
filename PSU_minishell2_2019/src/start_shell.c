/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** start_shell.c
*/

#include "my.h"

int start(char **env, char *buffer, char **argv)
{
    size_t bufsize = 32;
    myshell *stock = create_struct(env);

    while (1){
        my_printf("$---> ");
        if (getline(&buffer, &bufsize, stdin) == EOF)
            return (0);
        else if (my_strcmp(buffer, "exit\n") == 1)
            return (0);
        start_bis(env, buffer, stock);
    }
    return (0);
}

int start_bis(char **env, char *buffer, myshell *stock)
{
    char **buf_env = shell_str_to_array(buffer);
    char *str_stock = format_str(buf_env);
    buf_env = shell_str_to_array(str_stock);
    int y = 0;

    if (check_separator(buffer, env, stock) == 1)
        return (0);
    else if (my_strcmp(buf_env[0], "unsetenv\n") == 1)
        my_unsetenv(str_stock, stock);
    else
        start_ter(env, buf_env, stock, str_stock);
}

void start_ter(char **env, char **buf_env, myshell *stock, char *str_stock)
{
    if (my_strcmp(buf_env[0], "cd\n") == 1)
        cd_command(str_stock, stock, env);
    else if (my_strcmp(buf_env[0], "setenv\n") == 1 ||
    my_strcmp(buf_env[0], "env\n") == 1)
        set_and_unsetenv(stock, str_stock);
    else if (my_strcmp(buf_env[0], "echo\n") == 0 && buf_env[0] != NULL)
        builtins(env, str_stock);
}

char *format_str(char **buf_env)
{
    int y = 0;
    char *new = "\0";

    while (buf_env[y] != NULL){
        if (my_strlen(buf_env[y]) != 0){
            new = my_strcat_space(new, buf_env[y]);
        }
        y = y + 1;
    }
    return (new);
}

int nbr_line_of_env(char **env)
{
    int y = 0;

    while (env[y] != NULL){
        y = y + 1;
    }
    return (y);
}