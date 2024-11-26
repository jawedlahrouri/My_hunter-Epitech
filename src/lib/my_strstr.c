/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** Reproduce the behavior of the strstr function
*/

#include <stddef.h>
#include "../include/my.h"

static int check(char *str, char const *to_find, int i)
{
    int index;
    int lentf = my_strlen(to_find);

    for (int x = 0; x < lentf; x++) {
        if (str[i + x] != to_find[x]) {
            return 0;
        }
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    int lenstr = my_strlen(str);
    int index = -1;

    for (int i = 0; lenstr != i; i++) {
        if (check(str, to_find, i) == 1) {
            index = i;
            break;
        }
    }
    if (index == -1)
        return NULL;
    return str + index;
}
