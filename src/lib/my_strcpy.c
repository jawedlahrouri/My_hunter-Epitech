/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** Write a function that copies a string into another.
** The destination string will already have enough memory
** to copy the source string
*/

/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** send back the len of the input string which is nice
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
