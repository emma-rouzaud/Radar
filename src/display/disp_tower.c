/*
** EPITECH PROJECT, 2018
** disp.c
** File description:
** radar
*/

#include "include.h"

void print_t_hitbox(tower_t *tower, ctx_t *ctx)
{
	sfCircleShape_setOrigin(tower->hitbox, (sfVector2f){tower->radius, \
		tower->radius});
	sfCircleShape_setPosition(tower->hitbox, tower->pos);
	sfRenderWindow_drawCircleShape(ctx->window, tower->hitbox, NULL);
}

void my_print_tower(tower_t *tower, ctx_t *ctx)
{
	if (tower->texture != NULL) {
		sfSprite_setTexture(tower->sprite, tower->texture, sfFalse);
		sfSprite_setPosition(tower->sprite, tower->pos);
		sfSprite_setOrigin(tower->sprite, (sfVector2f){12, 12});
		sfRenderWindow_drawSprite(ctx->window, tower->sprite, NULL);
	} else {
		sfRectangleShape_setPosition(tower->rect, tower->pos);
		sfRectangleShape_setOrigin(tower->rect, (sfVector2f){10, 10});
		sfRenderWindow_drawRectangleShape(ctx->window, tower->rect, \
			NULL);
	}
}

void my_disp_tower(ctx_t *ctx, tower_t *tower)
{
	while (tower != NULL) {
		if (ctx->disp_sprite == 1)
			my_print_tower(tower, ctx);
		if (ctx->disp_hitbox == 1)
			print_t_hitbox(tower, ctx);
		tower = tower->next;
	}
}
