/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** setenv.c
*/

#include "my.h"

char **set_and_unsetenv(myshell *stock, char *buffer)
{
    char **buf_env = shell_str_to_array(buffer);
    char *str_stock = format_str(buf_env);
    buf_env = shell_str_to_array(str_stock);
    int line_y = 0;
    char *stock_bis;

    if (error_handling_env(buf_env) == 1)
        return (0);
    else if (my_strcmp(buf_env[0], "env") == 1 ||
    my_strcmp(buf_env[0], "setenv") == 1 && buf_env[1] == NULL)
        print_myenv(stock);
    else
        setenv_bis(buffer, stock);
}

int error_handling_env(char **buf_env)
{
    if (buf_env[3] != NULL){
        my_printf("setenv: Too many arguments.\n");
        return (1);
    }
    else if (buf_env[1] != NULL && my_char_isalphanumeric(buf_env[1][0]) != 1){
        my_printf("setenv: Variable name must begin with a letter.\n");
        return (1);
    }
    else if (buf_env[1] != NULL && my_str_isalphanumeric(buf_env[1]) != 1){
        my_printf("setenv: Variable name must ");
        my_printf("contain alphanumeric characters.\n");
        return (1);
    }
    return (0);
}

char **setenv_bis(char *buffer, myshell *stock)
{
    char **buf_env = shell_str_to_array(buffer);
    char *str_stock = format_str(buf_env);
    buf_env = shell_str_to_array(str_stock);
    char *val_one;
    char *val_two;
    int to_change = 0;

    if (buf_env[2] != NULL && check_elem_line_y(buf_env[1], stock) == -1){
        val_one = my_strcat_bis(buf_env[1], buf_env[2]);
        stock->my_newenv = insert_elem(stock->my_newenv, val_one);
        return (stock->my_newenv);
    }
    else if (buf_env[2] == NULL && check_elem_line_y(buf_env[1], stock) == -1){
        val_two = my_strcat_bis(buf_env[1], "");
        stock->my_newenv = insert_elem(stock->my_newenv, val_two);
        return (stock->my_newenv);
    }
    setenv_ter(buffer, stock, buf_env);
}

char **setenv_ter(char *buffer, myshell *stock, char **buf_env)
{
    int to_change = 0;

    if (buf_env[2] != NULL && check_elem_line_y(buf_env[1], stock)){
        to_change = check_elem_line_y(buf_env[1], stock);
        stock->my_newenv[to_change] = my_strcat_bis(buf_env[1], buf_env[2]);
        return (stock->my_newenv);
    }
    else if (buf_env[2] == NULL && check_elem_line_y(buf_env[1], stock)){
        to_change = check_elem_line_y(buf_env[1], stock);
        stock->my_newenv[to_change] = my_strcat_bis(buf_env[1], "");
        return (stock->my_newenv);
    }
}