/*
** EPITECH PROJECT, 2017
** list.c
** File description:
** radar
*/

#include "include.h"
int	my_getnbr(char const *str, int *i);

sfRectangleShape *create_p_hitbox(void)
{
	sfRectangleShape *hitbox = sfRectangleShape_create();

	sfRectangleShape_setSize(hitbox, (sfVector2f){20, 20});
	sfRectangleShape_setFillColor(hitbox, (sfColor){0, 0, 0, 0});
	sfRectangleShape_setOutlineThickness(hitbox, 1);
	sfRectangleShape_setOutlineColor(hitbox, sfWhite);
	return (hitbox);
}

void fill_new_plane2(plane_t *new, sfTexture *texture)
{
	new->texture = texture;
	new->rect = my_create_rect(sfBlue);
	new->sprite = sfSprite_create();
	new->hitbox = create_p_hitbox();
	new->hit = 0;
	new->x = 0;
}

void fill_new_plane(plane_t *new, char *str, sfTexture *texture)
{
	int i = 0;

	my_move_i(str, &i);
	new->init.x = my_getnbr(str, &i);
	my_move_i(str, &i);
	new->init.y = my_getnbr(str, &i);
	my_move_i(str, &i);
	new->fin.x = my_getnbr(str, &i);
	my_move_i(str, &i);
	new->fin.y = my_getnbr(str, &i);
	my_move_i(str, &i);
	new->speed = my_getnbr(str, &i);
	my_move_i(str, &i);
	new->delay = my_getnbr(str, &i);
	new->pos.x = new->init.x;
	new->pos.y = new->init.y;
	fill_new_plane2(new, texture);
}

plane_t *my_add_plane(plane_t *list, char *str, sfTexture *texture)
{
	plane_t *new = malloc(sizeof(*new));
	int total = my_count_nb_arg(str);

	if (total != 6) {
		free(new);
		return (NULL);
	}
	fill_new_plane(new, str, texture);
	new->next = list;
	list = new;
	return (list);
}

plane_t *init_planes(char *str)
{
	plane_t *planes = NULL;
	sfTexture *texture = sfTexture_createFromFile("ship.png", NULL);
	int i = 0;
	int total;

	total = my_count_nb_line(str);
	while (i != total) {
		if (str[0] == 'A')
			planes = my_add_plane(planes, str, texture);
		str += my_find_len_line(str);
		i++;
	}
	return (planes);
}
