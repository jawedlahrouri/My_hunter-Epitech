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
int manage_events(sfRenderWindow *window, sfEvent *event);
int is_mouse_touch_duck(sfSprite *sprite, sfRenderWindow *window);
int clicked(sfSprite *sprite, sfRenderWindow *window);
void move_sprite(sfSprite *duck, sfSprite *mouse, sfRenderWindow *window);
void click_event(sfSprite *duck, sfSprite *mouse, sfRenderWindow *window);
void game_loop(sfRenderWindow *window, sfSprite *duck,
    sfSprite *mouse, sfSprite *background);
int destroy_sprite(sfSprite *duck, sfSprite *mouse,
    sfSprite *background, sfRenderWindow *window);
int main(void);
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

#endif /*my.h*/
