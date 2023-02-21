/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** get_space.c
*/

#include "my.h"

char **create_first_cmd(char **buf_env)
{
    int y = 0;
    char **first_cmd = malloc(sizeof(char *) * 3 + 1);

    while (y != find_pipe_buf(buf_env)){
        first_cmd[y] = malloc(sizeof(char *) * 15);
        first_cmd[y] = buf_env[y];
        y = y + 1;
    }
    return (first_cmd);
}

char **create_second_cmd(char **buf_env)
{
    int y = 0;
    char **second_cmd = malloc(sizeof(char *) * 3 + 1);
    int y_bis = find_pipe_buf(buf_env) + 1;

    while (buf_env[y_bis] != NULL){
        second_cmd[y] = malloc(sizeof(char *) * 15);
        second_cmd[y] = buf_env[y_bis];
        y_bis = y_bis + 1;
        y = y + 1;
    }
    return (second_cmd);
}

char **create_simple_str_table(char **buf)
{
    int y = 0;
    char **stock = malloc(sizeof(char *) * 3 + 1);

    while (buf[y] != NULL){
        stock[y] = malloc(sizeof(char *) * 15);
        stock[y] = buf[y];
        y = y + 1;
    }
    return (stock);
}

void builtins_space(char **env, char **board, char **buf)
{
    char *res = NULL;
    int y = 0;
    char **stock = create_simple_str_table(buf);
    struct stat statbuf;
    stat(stock[0], &statbuf);

    while (board[y] != NULL){
        res = my_strcat(board[y], buf[0]);
        if (access(res, F_OK) != -1){
            execve(res, stock, env);
        } else
            y = y + 1;
    }
    if (statbuf.st_mode & S_IXUSR)
        execve(stock[0], stock, env);
}

int pipe_space(char **env, char **first_cmd, char **second_cmd, char **buf_env)
{
    int pfd[2];
    pid_t pid;

    if (pipe(pfd) == -1 || (pid = fork()) < 0)
        return (0);
    else if (pid == 0){
        close(pfd[1]);
        dup2(pfd[0], 0);
        close(pfd[0]);
        execve(find_cmd_path(buf_env, env, find_pipe_buf(buf_env) + 1),
        second_cmd, env);
    } else {
        close(pfd[0]);
        dup2(pfd[1], 1);
        close(pfd[1]);
        execve(find_cmd_path(buf_env, env, 0), first_cmd, env);
    }
    return (0);
}