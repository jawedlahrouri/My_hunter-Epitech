/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** starf'Allah
*/
#include "../include/my.h"
#include <stdlib.h>
#include <ctype.h>

static int skip_nonalphanum(const char *str, int i) {
    while (str[i] && !((str[i] >= 'a' && str[i] <= 'z') ||
                       (str[i] >= 'A' && str[i] <= 'Z') ||
                       (str[i] >= '0' && str[i] <= '9')))
        i++;
    return i;
}

int count_word(const char *str) {
    int word = 0, in_word = 0;
    for (int i = 0; str[i]; i++) {
        int is_alnum = ((str[i] >= 'a' && str[i] <= 'z') ||
                       (str[i] >= 'A' && str[i] <= 'Z') ||
                       (str[i] >= '0' && str[i] <= '9'));
        if (is_alnum && !in_word) {
            word++;
            in_word = 1;
        }
        if (!is_alnum) {
            in_word = 0;
        }
    }
    return word;
}

int word_size(const char *str, int act_pos) {
    int word_size = 0;
    act_pos = skip_nonalphanum(str, act_pos);
    while ((str[act_pos] >= 'a' && str[act_pos] <= 'z') || 
           (str[act_pos] >= 'A' && str[act_pos] <= 'Z') ||
           (str[act_pos] >= '0' && str[act_pos] <= '9')) {
        word_size++;
        act_pos++;
    }
    return word_size;
}

char **my_str_to_word_array(const char *str)
{
    int words = count_word(str);
    int act_pos = 0;
    char **array = malloc((words + 1) * sizeof(char *));
    for (int i = 0; i < words; i++) {
        act_pos = skip_nonalphanum(str, act_pos);
        int len = word_size(str, act_pos);
        array[i] = malloc((len + 1) * sizeof(char));
        for (int j = 0; j < len; j++, act_pos++)
            array[i][j] = str[act_pos];
        array[i][len] = '\0';
    }
    array[words] = NULL;
    return array;
}



