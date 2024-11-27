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


void move_sprite(sfSprite *duck, sfSprite *mouse, sfRenderWindow *window)
{
    static int frame = 0;
    int animation_framerate = 60;

    sfSprite_move(duck, (sfVector2f) {115, 0});
    if (sfSprite_getPosition(duck).x > 1920)
        sfSprite_setPosition(duck, (sfVector2f) {0, 0});
    sfRenderWindow_drawSprite(window, duck, NULL);
    sfRenderWindow_drawSprite(window, mouse, NULL);
    sfRenderWindow_display(window);
    if (frame == 0)
        animate_sprite(duck, 3);
    frame = (frame + 1) % animation_framerate;
}

void click_event(sfSprite *duck, sfSprite *mouse, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfSprite_setPosition(duck, (sfVector2f)
        {mouse_pos.x - 80, mouse_pos.y - 80});
}
