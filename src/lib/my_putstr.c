/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** putchar a string of char
*/

#include "../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;
    char x = 48 + i;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i = i + 1;
    }
}
