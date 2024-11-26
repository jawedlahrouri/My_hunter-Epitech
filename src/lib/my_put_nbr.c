/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** task07: my_put_nbr
*/

#include "../include/my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = - nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar('0' + (nb % 10));
}
