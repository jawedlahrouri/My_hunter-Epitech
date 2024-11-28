/*
** EPITECH PROJECT, 2024
** my_compute_power_rec
** File description:
** poweeeeeeeeeeeeerrrr2
*/


int my_compute_power_rec(int nb, int power)
{
    if (power == 0)
        return 1;
    if (power < 0)
        return 0;
    nb = nb * my_compute_power_rec(nb, power - 1);
    return nb;
}
