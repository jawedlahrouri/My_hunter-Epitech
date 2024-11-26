/*
** EPITECH PROJECT, 2024
** my_isneg.c
** File description:
** Write a function that displays either N if the
** integer passed as parameter is negative or P, if
** positive or null
*/

#include "../include/my.h"

int my_isneg(int nb)
{
    if (nb < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
}