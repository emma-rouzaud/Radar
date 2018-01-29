/*
** EPITECH PROJECT, 2017
** list.c
** File description:
** radar
*/

#include "include.h"
int	my_getnbr(char const *str, int *i);

sfConvexShape *create_z_hitbox(char *str, int total)
{
	sfConvexShape *shape = sfConvexShape_create();
	int i = 0;
	int j = 0;
	int x;
	int y;

	sfConvexShape_setPointCount(shape, total / 2);
	while (i < total / 2) {
		my_move_i(str, &j);
		x = my_getnbr(str, &j);
		my_move_i(str, &j);
		y = my_getnbr(str, &j);
		sfConvexShape_setPoint(shape, i, (sfVector2f){x, y});
		i++;;
	}
	sfConvexShape_setFillColor(shape, (sfColor){0, 0, 0, 0});
	sfConvexShape_setOutlineThickness(shape, 1);
	sfConvexShape_setOutlineColor(shape, sfRed);
	return (shape);
}

sfConvexShape *my_create_shape(char *str, int total, sfColor color)
{
	sfConvexShape *shape = sfConvexShape_create();
	int i = 0;
	int j = 0;
	int x;
	int y;

	sfConvexShape_setPointCount(shape, total / 2);
	while (i < total / 2) {
		my_move_i(str, &j);
		x = my_getnbr(str, &j);
		my_move_i(str, &j);
		y = my_getnbr(str, &j);
		sfConvexShape_setPoint(shape, i, (sfVector2f){x, y});
		i++;
	}
	sfConvexShape_setFillColor(shape, color);
	return (shape);
}

void my_fill_new_zone(zone_t *new, char *str, sfTexture *texture)
{
	int total = my_count_nb_arg(str);

	new->texture = texture;
	new->shape = my_create_shape(str, total, sfWhite);
	new->hitbox = create_z_hitbox(str, total);
}

zone_t *my_add_zone(zone_t *list, char *str, sfTexture *texture)
{
	zone_t *new = malloc(sizeof(*new));

	my_fill_new_zone(new, str, texture);
	if (new->shape == NULL) {
		free(new);
		return (NULL);
	}
	new->next = list;
	list = new;
	return (list);
}

zone_t *init_zone(char *str)
{
	zone_t *zone = NULL;
	int i = 0;
	int total;
	sfTexture *texture = sfTexture_createFromFile("meteorite.png", NULL);

	total = my_count_nb_line(str);
	while (i != total) {
		if (str[0] == 'D')
			zone = my_add_zone(zone, str, texture);
		str += my_find_len_line(str);
		i++;
	}
	return (zone);
}
