/*
** EPITECH PROJECT, 2024
** event.c
** File description:
** handle events
*/

#include "../include/my.h"

int manage_events(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return 1;
        }
    }
    return 0;
}

int is_mouse_touch_duck(sfSprite *sprite, sfRenderWindow *window)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    return (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y));
}

int clicked(sfSprite *sprite, sfRenderWindow *window)
{
    return (sfMouse_isButtonPressed(sfMouseLeft) &&
        is_mouse_touch_duck(sprite, window));
}
