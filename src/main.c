/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** screensaver
*/

#include "include.h"

void my_manage_zones_and_towers(tower_t *tower, zone_t *zone, \
	plane_t *plane, ctx_t *ctx)
{
	if (tower != NULL) {
		my_disp_tower(ctx, tower);
		my_prevent_col(plane, tower);
	}
	if (zone != NULL) {
		my_disp_zone(ctx, zone);
		my_check_collision_zone(plane, zone);
	}
}

void my_start_game(ctx_t *ctx, plane_t *plane, tower_t *tower, zone_t *zone)
{
	sfClock *clock;
	sfTime time;
	float seconds;

	clock = sfClock_create();
	sfRenderWindow_setFramerateLimit(ctx->window, 30);
	while (sfRenderWindow_isOpen(ctx->window) && my_check_end(plane) == 0) {
		my_check_event(ctx);
		my_disp_map(ctx);
		my_manage_zones_and_towers(tower, zone, plane, ctx);
		time = sfClock_getElapsedTime(clock);
		seconds = time.microseconds / 100000.0;
		if ((int)(seconds * 10) % 2 == 0)
			my_draw_line(plane, ctx);
		if (seconds > 1) {
			my_manage_delay(plane);
			sfClock_restart(clock);
		}
	}
}

void my_open_game(ctx_t *ctx, plane_t *plane, tower_t *tower, zone_t *zone)
{
	init_ctx(ctx);
	if (!ctx->window)
		return;
	my_start_game(ctx, plane, tower, zone);
	sfRenderWindow_destroy(ctx->window);
}

void my_load_game(char **av, ctx_t *ctx)
{
	plane_t *plane;
	tower_t *tower;
	zone_t *zone;
	char *str;

	str = my_load_file(av[1]);
	if (str == NULL) {
		my_putstr("error: could not load file\n");
		return;
	}
	plane = init_planes(str);
	if (plane == NULL)
		return;
	tower = init_towers(str);
	zone = init_zone(str);
	my_open_game(ctx, plane, tower, zone);
	my_destroy_structs(plane, tower, zone);
}

int main(int ac, char **av)
{
	ctx_t *ctx = malloc(sizeof(*ctx));

	if (ac != 2) {
		my_putstr("error: bad argument\n");
		return (84);
	}
	if (av[1][0] == '-' && av[1][1] == 'h')
		my_disp_usage();
	else
		my_load_game(av, ctx);
	free(ctx);
	return (0);
}
