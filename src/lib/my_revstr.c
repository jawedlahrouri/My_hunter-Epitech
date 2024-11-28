/*
** EPITECH PROJECT, 2024
** my_revstr.c
** File description:
** Write a function that reverses a string
*/

#include <stddef.h>
#include "../include/my.h"

char *my_revstr(char *str)
{
    int len = 0;
    char t;

    if (str == NULL) {
        return NULL;
    }
    while (str[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len / 2; i++) {
        t = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = t;
    }
    return str;
}
