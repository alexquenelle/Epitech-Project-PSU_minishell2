/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** .
*/

#include <stdarg.h>
#include "my.h"

int flags(char w, va_list ap)
{
    int j = 0;
    const char *k = "dcsui%";
    int (*fptr[5])(va_list) = { &va_put_nbr, &va_my_putchar,
                                &va_my_putstr, &va_my_put_nbru, &va_put_nbr };

    while (k[j] != '\0'){
        if (w == k[j])
            fptr[j](ap);
        j++;
    }
    return (0);
}

int my_printf(char *fmt, ...)
{
    int k = 0;
    va_list (ap);
    va_start(ap, fmt);
    while (fmt[k] != '\0'){
        if (fmt[k] == '%'){
        flags(fmt[k + 1], ap);
        k++;}
        else
        my_putchar(fmt[k]);
        k++;
    }
    va_end(ap);
    return (0);
}
