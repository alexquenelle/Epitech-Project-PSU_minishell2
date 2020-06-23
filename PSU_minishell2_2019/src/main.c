/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** main.c
*/

#include "my.h"

int main(int argc, char **argv, char **env)
{
    char *buffer = NULL;
    start(env, buffer, argv);
}