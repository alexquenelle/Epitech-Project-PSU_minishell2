/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** start_shell_bis.c
*/

#include "my.h"

char *get_home(myshell *stock, char *str)
{
    int i = -1;
    int len = my_strlen(str);
    int j = len + 1;
    int inc = 0;
    char *path;

    while (stock->my_newenv[++i])
        if (my_strcmp_custom(stock->my_newenv[i], str) == 1){
            if ((path = malloc(sizeof(char) *
            (my_strlen(stock->my_newenv[i] + len) + 1))) == NULL)
                return (0);
            while (stock->my_newenv[i][j]){
                path[inc++] = stock->my_newenv[i][j++];
            }
            path[inc] = 0;
        }
    return (path);
}

char **cd_command(char *buffer, myshell *stock, char **env)
{
    char **buf_env = shell_str_to_array(buffer);
    char *str_stock = format_str(buf_env);
    buf_env = shell_str_to_array(str_stock);
    char *home = get_home(stock, "HOME");
    char *path = {buf_env[1]};

    if (buf_env[1] == NULL)
        stock->a = chdir(home);
    else if (buf_env[1][0] == '-')
        no_path_cd(stock, buf_env, env);
    else {
        stock->old_pwd = getcwd(NULL, 250);
        stock->a = chdir(path);
    }
    if (stock->a == -1)
        my_printf("%s: Not a directory.\n", buf_env[1]);
    stock->pwd_to_display = my_strcat_bis("PWD", getcwd(NULL, 250));
    stock->pwd_to_change = check_elem_line_y("PWD", stock);
    stock->my_newenv[stock->pwd_to_change] = stock->pwd_to_display;
    return (stock->my_newenv);
}

int no_path_cd(myshell *stock, char **buf_env, char **env)
{
    int a = 0;
    char *path = {buf_env[1]};

    if (buf_env[1][0] == '-')
        a = chdir(stock->old_pwd);
    return (0);
}

char *get_old_pwd(char **env)
{
    int i = -1;
    int j = 7;
    int inc = 0;
    char *path;

    while (env[++i])
        if (env[i][0] == 'O' && env[i][1] == 'L'
        && env[i][2] == 'D' && env[i][3] == 'P'){
            if ((path = malloc(sizeof(char) *
            (my_strlen(env[i] + 7) + 1))) == NULL)
                return (0);
            while (env[i][j]){
                path[inc++] = env[i][j++];
            }
            path[inc] = 0;
        }
    return (path);
}