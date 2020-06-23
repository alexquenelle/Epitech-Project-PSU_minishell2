/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** separator.c
*/

#include "my.h"

int check_separator(char *buffer, char **env, myshell *stock)
{
    int inc = 0;
    char **buf_env = shell_str_to_array(buffer);
    char *str_stock = format_str(buf_env);
    buf_env = shell_str_to_array(str_stock);

    while (buffer[inc] != '\0'){
        if (buffer[inc] == ';'){
            exe_separator(buf_env, env, stock);
            return (1);
        }
        else if (buffer[inc] == '|'){
            exe_pipe(env, buffer);
            return (1);
        }
        inc = inc + 1;
    }
    return (0);
}

int exe_pipe(char **env, char *buffer)
{
    char **buf_env = shell_str_to_array(buffer);
    char *str_stock = format_str(buf_env);
    buf_env = shell_str_to_array(str_stock);
    __pid_t avoid_exit = fork();
    char **first_cmd = create_first_cmd(buf_env);
    char **second_cmd = create_second_cmd(buf_env);

    if (avoid_exit == 0)
        pipe_space(env, first_cmd, second_cmd, buf_env);
    else
        wait(NULL);
    return (0);
}

char *find_cmd_path(char **buf_env, char **env, int i)
{
    char *path = get_path(env);
    char **board = shell_str_to_array(path);
    int y = 0;
    char *res = NULL;

    while (board[y] != NULL){
        res = my_strcat(board[y], buf_env[i]);
        if (access(res, F_OK) != -1){
            return (res);
        } else
            y = y + 1;
    }
}

int find_pipe_buf(char **buf_env)
{
    int i = 0;

    while (buf_env[i] != NULL){
        if (my_strcmp(buf_env[i], "|") == 1 ||
        my_strcmp(buf_env[i], ";") == 1){
            return (i);
        }
        i = i + 1;
    }
    return (0);
}

void exe_separator(char **buf_env, char **env, myshell *stock)
{
    char *str_stock = format_str(buf_env);
    char *new_str = cut_separator(str_stock, 0);
    char *first_cmd = cut_separator(str_stock, 0);
    char *second_cmd = cut_separator(str_stock, my_strlen(first_cmd) + 1);
    int y = 0;
    char **all_command = fill_my_separator(first_cmd, second_cmd, str_stock);

    while (all_command[y] != NULL){
        if (all_command[y][0] == 'c' && all_command[y][1] == 'd')
            cd_command(all_command[y], stock, env);
        else
            builtins(env, all_command[y]);
        y = y + 1;
    }
}