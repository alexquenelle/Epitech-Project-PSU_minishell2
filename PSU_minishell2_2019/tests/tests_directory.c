/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** tests_directory.c
*/

#include  <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_stdout(void);

Test (isdirectory, permission_denied, .init = redirect_all_stdout)
{
    char *buffer = "/usr/bin\n";
    char *res = "/bin/ls\n";
    isdirectory(buffer, res);
    cr_assert_stdout_eq_str("/usr/bin: Permission denied.\n");
}

Test (isdirectory, command_not_found, .init = redirect_all_stdout)
{
    char *buffer = "mdr";
    char *res = "/var/lib/snapd/snap/bin/mdr";
    isdirectory(buffer, res);
    cr_assert_stdout_eq_str("mdr: Command not found.\n");
}