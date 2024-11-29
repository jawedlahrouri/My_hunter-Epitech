/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** Header avec les fonctions
*/



#ifndef MY_H
    #define MY_H
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Network.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <stdio.h>
    #include <stdarg.h>
int manage_events(sfRenderWindow *window, sfEvent *event);
int is_mouse_touch_duck(sfSprite *sprite, sfRenderWindow *window);
int clicked(sfSprite *sprite, sfRenderWindow *window);
void move_sprite(sfSprite *duck, sfSprite *mouse, sfRenderWindow *window);
void click_event(sfSprite *duck, sfSprite *mouse, sfRenderWindow *window);
void game_loop(sfRenderWindow *window, sfSprite *duck,
    sfSprite *mouse, sfSprite *background);
int destroy_sprite(sfSprite *duck, sfSprite *mouse,
    sfSprite *background, sfRenderWindow *window);
int main(int argc, char **argv);
sfSprite *create_sprite(char *filepath, int x, int y);
void animate_sprite(sfSprite *sprite, int frame_count);
sfRenderWindow *create_window(int width, int height, char *title);
void destroy_window(sfRenderWindow *window);
int destroy_sprite(sfSprite *duck, sfSprite *mouse,
    sfSprite *background, sfRenderWindow *window);
void follow_mouse(sfSprite *mouse, sfRenderWindow *window);
void play_music(const char *filepath);
void falling_duck(sfRenderWindow *window, sfVector2f start_pos,
    sfSprite *falling_sprite);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_putchar(char c);
void flag_d(va_list list);
void flag_o(va_list list);
void flag_s(va_list list);
void flag_i(va_list list);
void flag_c(va_list list);
void flag_percent(va_list list);
void flag_x2(va_list list);
void flag_x(va_list list);
int flag_detector(const char *format, int i, va_list list);
int my_printf(const char *format, ...);
#endif
