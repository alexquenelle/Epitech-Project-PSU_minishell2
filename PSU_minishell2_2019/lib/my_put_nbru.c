/*
** EPITECH PROJECT, 2019
** my_put_nbru
** File description:
** .
*/

#include "my.h"

void my_putchar(char c);

int my_put_nbru(long int nb)
{
    long int nombre = 0;

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
