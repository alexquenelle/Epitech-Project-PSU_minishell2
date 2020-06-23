/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <stddef.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

typedef struct myshell
{
    char **my_newenv;
    char *old_pwd;
    int a;
    int pwd_to_change;
    char *pwd_to_display;
}myshell;

/*minishell functions :*/

int isdirectory(char *buffer, char *res);
char **remove_elem(char **env, char *str, myshell *stock);
char **my_unsetenv(char *buffer, myshell *stock);
int check_elem_line_y(char *str, myshell *stock);
char *get_home(myshell *stock, char *str);
char **cd_command(char *buffer, myshell *stock, char **env);
int my_strcmp_custom(char *str1, char *str2);
int check_elem(char *buffer, myshell *stock);
char **insert_elem(char **env, char *str);
myshell *create_struct(char **env);
char **setenv_bis(char *buffer, myshell *stock);
int print_myenv(myshell *stock);
int check(char *buffer);
int my_char_isalphanumeric(char letter);
char *my_strcat(char *dest, char const *src);
char *my_strcat_bis(char *dest, char *src);
char *my_strcpy(char *dest, char const *src);
int nbr_line_of_env(char **env);
char **set_and_unsetenv (myshell *stock, char *buffer);
int builtins(char **env, char *buffer);
char *get_path(char **env);
int my_strlen(char const *str);
char **shell_str_to_array(char *str);
int my_putstr(char const *str);
int my_strcmp(char *str1, char *str2);
int start (char **env, char *buffer, char **argv);
char **setenv_ter(char *buffer, myshell *stock, char **buf_env);
int start_bis(char **env, char *buffer, myshell *stock);
int error_handling_env(char **buf_env);
int my_str_isalphanumeric(char *str);
char *my_strcat_space(char *dest, char const *src);
char *format_str(char **buf_env);
void start_ter(char **env, char **buf_env, myshell *stock, char *str_stock);
int check_separator(char *buffer, char **env, myshell *stock);
void exe_separator(char **buf_env, char **env, myshell *stock);
int exe_pipe(char **env, char *buffer);
char *find_cmd_path(char **buf_env, char **env, int i);
int find_pipe_buf(char **buf_env);
char **create_first_cmd(char **buf_env);
char **create_second_cmd(char **buf_env);
char **create_simple_str_table(char **buf);
void redirect_all_stdout(void);
void builtins_space(char **env, char **board, char **buf);
int pipe_space(char **env, char **first_cmd, char **second_cmd, char **buf_env);
char **shell_str_to_array_space(int i, int y, int n, int x, char *str);
int no_path_cd(myshell *stock, char **buf_env, char **env);
char *get_old_pwd(char **env);
char *cut_separator(char *str, int i);
int count_separator(char *str);
char **fill_my_separator(char *first_cmd, char *second_cmd, char *str_stock);
char **create_word_array(char *first_cmd, char *second_cmd);

/*my_printf functions :*/

int my_put_nbru(long int nb);
int my_put_nbr(int nb);
int flags(char w, va_list ap);
void my_putchar (char c);
int my_printf(char *fmt, ...);
int va_my_putchar(va_list ap);
int va_put_nbr(va_list ap);
int va_my_putstr(va_list ap);
int va_my_put_nbru(va_list ap);

#endif /* MY_H_ */
