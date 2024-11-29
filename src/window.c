/*
** EPITECH PROJECT, 2024
** open_window
** File description:
** afficher une fenetre
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
#include <SFML/Graphics/RenderWindow.h>
#include "../include/my.h"

sfRenderWindow *create_window(int width, int height, char *title)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, title, sfClose
        | sfFullscreen, NULL);

    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return window;
}

void destroy_window(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
}
