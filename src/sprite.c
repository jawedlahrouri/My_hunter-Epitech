/*
** EPITECH PROJECT, 2024
** sprite.c
** File description:
** make move sprtes
*/

#include <SFML/Graphics.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>

sfSprite *create_sprite(char *filepath, int x, int y)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfIntRect area = {0, 0, x, y};
    sfVector2f scale = {1, 1};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, area);
    sfSprite_setScale(sprite, scale);
    return sprite;
}
void animate_sprite(sfSprite *sprite, int frame_count)
{
    sfIntRect area = sfSprite_getTextureRect(sprite);

    area.left = (area.left + 110);
    if (area.left >= frame_count * 110)
        area.left = 0;
    sfSprite_setTextureRect(sprite, area);
}
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
    int data[] = {sfSprite_getPosition(sprite).x, sfSprite_getPosition(sprite).y,
        sfSprite_getGlobalBounds(sprite).width, sfSprite_getGlobalBounds(sprite).height,
        sfMouse_getPositionRenderWindow(window).x, sfMouse_getPositionRenderWindow(window).y};
    return (((data[4] > data[0]) && (data[4] < (data[0] + data[2]))) &&
        ((data[5] > data[1]) && (data[5] < (data[1] + data[3]))));
}

int clicked(sfSprite *sprite, sfRenderWindow *window)
{
    return (sfMouse_isButtonPressed(sfMouseLeft) &&
        is_mouse_touch_duck(sprite, window)); 
}

int click_event(sfSprite *duck, sfSprite *mouse, sfRenderWindow *window)
{

    sfSprite_setPosition(mouse, (sfVector2f)
    {sfMouse_getPositionRenderWindow(window).x - (80),
    sfMouse_getPositionRenderWindow(window).y - (80)});
    return 0;
}

int move_sprite(sfSprite *duck, sfSprite *mouse, sfRenderWindow *window)
{
    int frame = 0;
    int animation_framerate = 15;

    sfSprite_move(duck, (sfVector2f) {5, 0});
    if (sfSprite_getPosition(duck).x > 1920)
        sfSprite_setPosition(duck, (sfVector2f) {0, 0});
    sfRenderWindow_drawSprite(window, duck, NULL);
    sfRenderWindow_drawSprite(window, mouse, NULL);
    sfRenderWindow_display(window);
    if (frame == 0)
        animate_sprite(duck, 3);
    frame = (frame + 1) % animation_framerate;
    return 0;
}

int destroy_sprite(sfSprite *duck, sfSprite *mouse, sfSprite *background, sfRenderWindow *window)
{
    sfSprite_destroy(duck);
    sfSprite_destroy(mouse);
    sfSprite_destroy(background);
    sfRenderWindow_destroy(window);
}

int main(void)
{
    sfVideoMode mode = {1734, 900, 32};
    sfUint32 style = {sfClose | sfResize};
    sfRenderWindow *window = sfRenderWindow_create(mode, "AAAAARH", style, 0);
    sfEvent event = {0};
    sfSprite *first_sprite = create_sprite("image/meguduck.png", 110, 95);
    sfSprite *second_sprite = create_sprite("image/HOLLOW_PURPLE.png", 160, 160);
    sfSprite *background = create_sprite("image/shinjuku.png", 1734, 900);

    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfWhite);
        if (manage_events(window, &event))
            return 0;
        sfRenderWindow_drawSprite(window, background, NULL);
        if (clicked(first_sprite, window) == 1)
            click_event(first_sprite, second_sprite, window);
        move_sprite(first_sprite, second_sprite, window);
    }
    destroy_sprite(first_sprite, second_sprite, background, window);
}
