/*
** EPITECH PROJECT, 2018
** disp_map.c
** File description:
** radar
*/

#include "include.h"

void my_disp_map(ctx_t *ctx)
{
	sfRenderWindow_clear(ctx->window, sfBlack);
	if (ctx->texture != NULL)
		sfSprite_setTexture(ctx->sprite, ctx->texture, sfFalse);
	sfRenderWindow_drawSprite(ctx->window, ctx->sprite, NULL);
}
