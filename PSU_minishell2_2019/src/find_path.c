/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** find_path.c
*/

#include "my.h"

char *get_path(char **env)
{
    int i = -1;
    int j = 5;
    int inc = 0;
    char *path;

    while (env[++i])
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
        && env[i][3] == 'H' && env[i][4] == '='){
            if ((path = malloc(sizeof(char) *
            (my_strlen(env[i] + 5) + 1))) == NULL)
                return (0);
            while (env[i][j]){
                path[inc++] = env[i][j++];
            }
            path[inc] = 0;
        }
    return (path);
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *res = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)) + 1);

    if (dest != NULL){
        for (i; dest[i] != '\0'; i = i + 1){
            res[i] = dest[i];
        }
    }
    res[i] = '/';
    i = i + 1;
    while (src[j] != '\0'){
        res[i] = src[j];
        i = i + 1;
        j = j + 1;
    }
    res[i] = '\0';
    return (res);
    free(res);
}

int builtins(char **env, char *buffer)
{
    char *path = get_path(env);
    char **board = shell_str_to_array(path);
    char *res;
    char **buf = shell_str_to_array(buffer);
    char *str_stock = format_str(buf);
    buf = shell_str_to_array(str_stock);
    __pid_t pid = fork();
    int wstatus;

    if (pid == 0){
        builtins_space(env, board, buf);
        if (isdirectory(buffer, res) == -1)
            return (0);
    } else
        while (waitpid(pid, &wstatus, 0) != -1 &&
        !WIFEXITED(wstatus))
            if (WIFSIGNALED(wstatus) && WTERMSIG(wstatus) == SIGSEGV)
                my_printf("Segmentation fault\n");
            if (WIFSIGNALED(wstatus) && WTERMSIG(wstatus) == SIGFPE)
                my_printf("Floating exception\n");
}

int isdirectory(char *buffer, char *res)
{
    struct stat statbuf;
    char **buf = shell_str_to_array(buffer);
    char *str_stock = format_str(buf);
    buf = shell_str_to_array(str_stock);
    stat(buf[0], &statbuf);

    if (S_ISDIR(statbuf.st_mode) || S_ISREG(statbuf.st_mode)
    && !(statbuf.st_mode & S_IXUSR)){
        my_printf("%s: Permission denied.\n", buf[0]);
        return (-1);
    }
    else if (access(res, F_OK) == -1){
        my_printf("%s: Command not found.\n", buffer);
        return (-1);
    }
}