/*
** EPITECH PROJECT, 2024
** my_hunter.c
** File description:
** menu before the game
*/

#include "../include/my.h"

int point_trapeze(sfVector2i p)
{
    sfVector2i A = {1020, 320};
    sfVector2i B = {1615, 395};
    sfVector2i C = {1585, 320};
    sfVector2i D = {1165, 520};
    float area1 = fabs((A.x * (B.y - p.y) + B.x * (p.y - A.y)
    + p.x * (A.y - B.y)) / 2.0);
    float area2 = fabs((B.x * (C.y - p.y) + C.x * (p.y - B.y)
    + p.x * (B.y - C.y)) / 2.0);
    float area3 = fabs((C.x * (D.y - p.y) + D.x * (p.y - C.y)
    + p.x * (C.y - D.y)) / 2.0);
    float area4 = fabs((D.x * (A.y - p.y) + A.x * (p.y - D.y)
    + p.x * (D.y - A.y)) / 2.0);
    float trap_area = fabs((A.x * (B.y - D.y) + B.x * (D.y - A.y)
    + D.x * (A.y - B.y)) / 2.0) + fabs((B.x * (C.y - D.y) + C.x *
    (D.y - B.y) + D.x * (B.y - C.y)) / 2.0);

    return (area1 + area2 + area3 + area4) <= trap_area;
}

int menu_events(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed ||
            (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape))
            sfRenderWindow_close(window);
        if ((event->type == sfEvtKeyPressed &&
            event->key.code == sfKeyEnter) ||
            (event->type == sfEvtMouseButtonPressed &&
            point_trapeze(sfMouse_getPositionRenderWindow(window))))
            return 0;
    }
    return 1;
}

void display_menu(sfRenderWindow *window, sfSprite *bg, sfText *text)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, bg, NULL);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
}

void show_menu(sfRenderWindow *window)
{
    sfEvent event;
    sfSprite *background = create_sprite("image/menu.jpg", 1920, 1080);
    sfFont *font = sfFont_createFromFile("font/font.ttf");
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setString(text, "Click on button BATTLE or\n Press Enter to Start");
    sfText_setCharacterSize(text, 40);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1100, 700});
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    while (sfRenderWindow_isOpen(window) && menu_events(window, &event))
        display_menu(window, background, text);
    sfText_destroy(text);
    sfFont_destroy(font);
    sfSprite_destroy(background);
}
