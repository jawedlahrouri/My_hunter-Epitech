/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** a function that concatenates two strings
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int lendest = my_strlen(dest);
    int srclen = my_strlen(src);
    int totallen = lendest + srclen;

    for (int i = 0; i != srclen; i++) {
        dest[i + lendest] = src[i];
    }
    dest[totallen + 1] = '\0';
    return (dest);
}
