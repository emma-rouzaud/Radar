/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** screensaver
*/

#include "include.h"

int my_check_end(plane_t *plane)
{
	int check = 0;

	while (plane != NULL) {
		if (plane->pos.y <= plane->fin.y - plane->speed || \
plane->pos.y >= plane->fin.y + plane->speed )
			check++;
		plane = plane->next;
	}
	return ((check == 0) ? 1 : 0);
}

void my_check_keys(sfEvent event, ctx_t *ctx)
{
	if (event.key.code == sfKeyL)
		ctx->disp_hitbox = (ctx->disp_hitbox == 0) ? 1 : 0;
	if (event.key.code == sfKeyS)
		ctx->disp_sprite = (ctx->disp_sprite == 0) ? 1 : 0;

}

void my_check_event(ctx_t *ctx)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(ctx->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(ctx->window);
		if (event.type == sfEvtKeyPressed)
			my_check_keys(event, ctx);
	}
}
