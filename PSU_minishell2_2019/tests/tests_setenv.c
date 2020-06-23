/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** tests_setenv.c
*/

#include  <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (set_and_unsetenv, test_setenv, .init = redirect_all_stdout)
{
    char *env[4] = {"test", "criterion", "bis", NULL};
    char *buffer = "setenv test test test";
    myshell*stock = create_struct(env);
    set_and_unsetenv(stock, buffer);
    cr_assert_stdout_eq_str("setenv: Too many arguments.\n");
}

Test (set_and_unsetenv, test_setenv_bis, .init = redirect_all_stdout)
{
    char *env[4] = {"test", "criterion", "bis", NULL};
    char *buffer = "setenv 5test test";
    myshell*stock = create_struct(env);
    set_and_unsetenv(stock, buffer);
    cr_assert_stdout_eq_str
    ("setenv: Variable name must begin with a letter.\n");
}

Test (my_unsetenv, test_unsetenv, .init = redirect_all_stdout)
{
    char *env[4] = {"test", "criterion", "bis", NULL};
    char *buffer = "unsetenv";
    myshell*stock = create_struct(env);
    my_unsetenv(buffer, stock);
    cr_assert_stdout_eq_str("Too few arguments.\n");
}