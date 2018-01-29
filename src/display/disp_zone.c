/*
** EPITECH PROJECT, 2018
** disp.c
** File description:
** radar
*/

#include "include.h"

void my_print_zone(zone_t *zone, ctx_t *ctx)
{
	if (zone->texture != NULL)
		sfConvexShape_setTexture(zone->shape, zone->texture, sfFalse);
	sfRenderWindow_drawConvexShape(ctx->window, zone->shape, NULL);
}

void my_disp_zone(ctx_t *ctx, zone_t *zone)
{
	while (zone != NULL) {
		if (ctx->disp_sprite == 1)
			my_print_zone(zone, ctx);
		if (ctx->disp_hitbox == 1)
			sfRenderWindow_drawConvexShape(ctx->window, \
				zone->hitbox, NULL);
		zone = zone->next;
	}
}
