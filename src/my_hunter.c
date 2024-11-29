/*
** EPITECH PROJECT, 2024
** my_hunter.c
** File description:
** make the game
*/

#include "../include/my.h"

void game_loop(sfRenderWindow *window, sfSprite *duck,
    sfSprite *mouse, sfSprite *background)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfWhite);
        if (manage_events(window, &event))
            break;
        sfRenderWindow_drawSprite(window, background, NULL);
        if (clicked(duck, window))
            click_event(duck, mouse, window);
        move_sprite(duck, mouse, window);
        sfRenderWindow_drawSprite(window, duck, NULL);
        sfRenderWindow_drawSprite(window, mouse, NULL);
        sfRenderWindow_display(window);
        follow_mouse(mouse, window);
    }
}

int destroy_sprite(sfSprite *duck, sfSprite *mouse,
    sfSprite *background, sfRenderWindow *window)
{
    sfSprite_destroy(duck);
    sfSprite_destroy(mouse);
    sfSprite_destroy(background);
    sfRenderWindow_destroy(window);
    return 0;
}

int main(int argc, char **argv)
{
    sfRenderWindow *window = create_window(1734, 900, "AAAAARH");
    sfSprite *duck = create_sprite("image/duck.png", 110, 95);
    sfSprite *mouse = create_sprite("image/crosshair.png", 80, 80);
    sfSprite *background = create_sprite("image/background.png", 1920, 1080);

    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        my_printf("CREDIT : Jawed Lahrouri\n");
        my_printf("Bonus: there is a score system that display the number of");
        my_printf("that you kill in your terminal.\n");
        return 0;
        }
    }
    play_music("ogg/sukuna.ogg");
    game_loop(window, duck, mouse, background);
    destroy_sprite(duck, mouse, background, window);
    return 0;
}

void play_music(const char *filepath)
{
    sfMusic *music = sfMusic_createFromFile(filepath);

    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
}
