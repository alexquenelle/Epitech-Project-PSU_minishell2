/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** .
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int nombre = 0;

    if (nb < 0) {
        my_putchar('-');
        if (nb < -10)
            my_put_nbr(nb/10 * -1);
        my_putchar(nb%10 * - 1 + 48);
        return (0);
    }
    if (nb > 9)
        my_put_nbr(nb/10);
    nombre = nb % 10 + 48;
    my_putchar(nombre);
    return (0);
}
