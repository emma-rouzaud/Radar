/*
** EPITECH PROJECT, 2017
** line.c
** File description:
** radar
*/

#include "include.h"

void my_manage_delay(plane_t *plane)
{
	while (plane != NULL) {
		if (plane->delay > 0)
			plane->delay -= 1;
		plane = plane->next;
	}
}

void my_move_plane(plane_t *plane, ctx_t *ctx)
{
	double a = (plane->init.y - plane->fin.y == 0 ? 1 :\
	plane->init.y - plane->fin.y) / (plane->init.x - plane->fin.x\
	== 0 ? 1 : plane->init.x - plane->fin.x);
	double b = plane->init.y;
	double dist = sqrt(2);
	int count = 2;

	if ((plane->pos.y <= plane->fin.y - plane->speed || \
	plane->pos.y >= plane->fin.y + plane->speed ) && plane->delay <= 0) {
		while (dist < plane->speed / 5) {
			(plane->init.x > plane->fin.x) ? plane->x-- : \
			plane->x++;
			plane->pos.y = a * plane->x + b;
			dist = sqrt(pow(count, 2) + pow(count, 2));
			count++;
		}
		plane->pos.x = plane->init.x + plane->x;
		my_disp_plane(ctx, plane);
	}
}

void my_draw_line(plane_t *plane, ctx_t *ctx)
{
	int hit = 0;

	while (plane != NULL) {
		hit = my_check_collision_plane(plane);
		if (plane->hit == 1 || hit == 1) {
			plane->pos.y = plane->fin.y;
			plane->hit = hit;
		}
		my_move_plane(plane, ctx);
		plane = plane->next;
		hit = 0;
	}
	sfRenderWindow_display(ctx->window);
}
