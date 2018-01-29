/*
** EPITECH PROJECT, 2018
** disp.c
** File description:
** radar
*/

#include "include.h"

void my_print_p_hitbox(plane_t *plane, ctx_t *ctx)
{
	sfRectangleShape_setPosition(plane->hitbox, plane->pos);
	sfRenderWindow_drawRectangleShape(ctx->window, plane->hitbox, NULL);
}

void my_print_plane(plane_t *plane, ctx_t *ctx)
{
	if (plane->texture != NULL) {
		sfSprite_setTexture(plane->sprite, plane->texture, sfFalse);
		sfSprite_setPosition(plane->sprite, (sfVector2f){\
		plane->pos.x + 10, plane->pos.y + 10});
		sfSprite_setOrigin(plane->sprite, (sfVector2f){10, 10});
		(plane->init.x < plane->fin.x) ? sfSprite_setRotation(
		plane->sprite, atan((plane->fin.y - plane->init.y) / \
		(plane->fin.x - plane->init.x)) * 180 / M_PI + 90) : \
		sfSprite_setRotation(plane->sprite, \
		atan((plane->fin.y - plane->init.y) / (plane->fin.x - \
		plane->init.x)) * 180 / M_PI + 270);
		sfRenderWindow_drawSprite(ctx->window, plane->sprite, NULL);
	} else {
		sfRectangleShape_setPosition(plane->rect, plane->pos);
		sfRenderWindow_drawRectangleShape(ctx->window, plane->rect, \
		NULL);
	}
}

void my_disp_plane(ctx_t *ctx, plane_t *plane)
{
	if (ctx->disp_sprite == 1)
		my_print_plane(plane, ctx);
	if (ctx->disp_hitbox == 1)
		my_print_p_hitbox(plane, ctx);
}
