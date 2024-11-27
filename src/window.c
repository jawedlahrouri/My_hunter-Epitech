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
    sfUint32 style = {sfClose | sfResize};
    sfRenderWindow *window = sfRenderWindow_create(mode, title, style, NULL);
    sfRenderWindow_setFramerateLimit(window, 10);
    return window;
}

void destroy_window(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
}
