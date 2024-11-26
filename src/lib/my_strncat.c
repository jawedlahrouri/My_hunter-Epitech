/*
** EPITECH PROJECT, 2024
** my_strncat
** File description:
** WIP
*/

#include "../include/my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int lendest = my_strlen(dest);
    int srclen = my_strlen(src);
    int totallen = lendest + srclen;
    int ogn = n;

    for (int i = 0; n != 0; i++) {
        dest[i + lendest] = src[i];
        n = n - 1;
    }
    dest[lendest + ogn + 1] = '\0';
    return (dest);
}
