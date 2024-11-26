/*
** EPITECH PROJECT, 2024
** open_window
** File description:
** afficher une fenetre
*/

#include <SFML/Graphics.h>

void care_event(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void display_window(sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_display(window);
}

sfRenderWindow *make_window(unsigned int width, unsigned int height)
{
    sfVideoMode mode = {width, height, 32};

    return (sfRenderWindow_create(mode, "CSFML Window", sfResize | sfClose, NULL));
}

void game_loop(sfRenderWindow *window)
{
    while (sfRenderWindow_isOpen(window)) {
        handle_events(window);
        render_window(window);
    }
}

int main(void)
{
    sfRenderWindow *window = init_window(800, 600);

    game_loop(window);
    sfRenderWindow_destroy(window);
    return (0);
}
