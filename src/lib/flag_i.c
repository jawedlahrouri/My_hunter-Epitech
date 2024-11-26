/*
** EPITECH PROJECT, 2024
** Flag i
** File description:
** flag i
*/

#include <stdio.h>
#include <stdarg.h>
#include "../include/my.h"

void flag_i(va_list list)
{
    my_put_nbr(va_arg(list, int));
}
