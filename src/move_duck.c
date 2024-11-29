/*
** EPITECH PROJECT, 2024
** movement.c
** File description:
** make move things
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
#include <SFML/Graphics/RenderWindow.h>
#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

int score = 0;

void move_sprite(sfSprite *duck, sfSprite *mouse, sfRenderWindow *window)
{
    static int frame = 0;
    int animation_framerate = 5;
    float random_y = rand() % 800;

    sfSprite_move(duck, (sfVector2f) {20, 0});
    if (sfSprite_getPosition(duck).x > 1920)
        sfSprite_setPosition(duck, (sfVector2f) {0, random_y});
    sfRenderWindow_drawSprite(window, duck, NULL);
    sfRenderWindow_drawSprite(window, mouse, NULL);
    sfRenderWindow_display(window);
    if (frame == 0)
        animate_sprite(duck, 3);
    frame = (frame + 1) % animation_framerate;
}

void click_event(sfSprite *duck, sfSprite *mouse, sfRenderWindow *window)
{
    sfSprite *falling_sprite = create_sprite("image/ded.png", 60, 110);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect duck_bounds = sfSprite_getGlobalBounds(duck);
    float random_y = rand() % 800;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&duck_bounds, mouse_pos.x, mouse_pos.y)) {
            sfSprite_setPosition(duck, (sfVector2f){0, random_y});
            falling_duck(window, (sfVector2f){mouse_pos.x,
                mouse_pos.y}, falling_sprite);
        display_score();
        }
    }
}

void falling_duck(sfRenderWindow *window, sfVector2f start_pos,
    sfSprite *falling_sprite)
{
    sfSprite *background = create_sprite("image/background.png", 1734, 900);

    sfSprite_setPosition(falling_sprite, start_pos);
    while (sfSprite_getPosition(falling_sprite).y < 1080) {
        sfRenderWindow_clear(window, sfBlack);
        sfSprite_move(falling_sprite, (sfVector2f){0, 30});
        sfRenderWindow_drawSprite(window, background, NULL);
        sfRenderWindow_drawSprite(window, falling_sprite, NULL);
        sfRenderWindow_display(window);
    }
}

void display_score(void)
{
    score += 1;
    my_printf("score: %d\n", score);
}