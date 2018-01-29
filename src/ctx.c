/*
** EPITECH PROJECT, 2018
** ctx.c
** File description:
** radar
*/

#include "include.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
	sfUint8 *pixels = malloc(sizeof(sfUint8) * (width * height * 4));
	framebuffer_t *buffer = malloc(sizeof(framebuffer_t));
	unsigned int i = 0;

	while (i != width * height * 4) {
		pixels[i] = '0';
		i++;
	}
	buffer->width = width;
	buffer->height = height;
	buffer->pixels = pixels;
	return (buffer);
}

void init_ctx(ctx_t *ctx)
{
	ctx->width = 1000;
	ctx->height = 600;
	ctx->mode = (sfVideoMode){1000, 600, 32};
	ctx->buffer = framebuffer_create(ctx->width, ctx->height);
	ctx->texture = sfTexture_createFromFile("space.jpg", NULL);
	ctx->sprite = sfSprite_create();
	ctx->size = 100;
	ctx->window = sfRenderWindow_create(ctx->mode, "SFML window",
	sfResize | sfClose, NULL);
	ctx->disp_hitbox = 1;
	ctx->disp_sprite = 1;
}
