/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_flag.c
*/

#include <stdarg.h>
#include "my.h"

int va_my_putchar(va_list ap)
{
    char to_show = va_arg(ap, int);

    my_putchar(to_show);
    return (0);
}

int va_put_nbr(va_list ap)
{
    int to_show = va_arg(ap, int);

    my_put_nbr(to_show);
    return (0);
}

int va_my_putstr(va_list ap)
{
    char *to_show = va_arg(ap, char *);

    my_putstr(to_show);
    return (0);
}

int va_my_put_nbru(va_list ap)
{
    long int to_show = va_arg(ap, unsigned int);

    my_put_nbru(to_show);
    return (0);
}