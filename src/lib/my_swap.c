/*
** EPITECH PROJECT, 2024
** my_swap.c
** File description:
** swap swap
*/
#include "../include/my.h"

void my_swap(int *a, int *b)
{
    int As = *a;

    *a = *b;
    *b = As;
}
