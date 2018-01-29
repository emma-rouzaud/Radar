/*
** EPITECH PROJECT, 2017
** list.c
** File description:
** radar
*/

#include "include.h"
int	my_getnbr(char const *str, int *i);

sfCircleShape *create_t_hitbox(int radius)
{
	sfCircleShape *hitbox = sfCircleShape_create();

	sfCircleShape_setRadius(hitbox, radius);
	sfCircleShape_setFillColor(hitbox, (sfColor){0, 0, 0, 0});
	sfCircleShape_setOutlineThickness(hitbox, 1);
	sfCircleShape_setOutlineColor(hitbox, sfWhite);
	return (hitbox);
}

sfRectangleShape *my_create_rect(sfColor color)
{
	sfRectangleShape *rect = sfRectangleShape_create();

	sfRectangleShape_setSize(rect, (sfVector2f){20, 20});
	sfRectangleShape_setFillColor(rect, color);
	return (rect);
}

void fill_new_tower(tower_t *new, char *str, sfTexture *texture)
{
	int i = 0;

	new->texture = texture;
	new->rect = my_create_rect(sfYellow);
	new->sprite = sfSprite_create();
	my_move_i(str, &i);
	new->pos.x = my_getnbr(str, &i);
	my_move_i(str, &i);
	new->pos.y = my_getnbr(str, &i);
	my_move_i(str, &i);
	new->radius = my_getnbr(str, &i);
	new->hitbox = create_t_hitbox(new->radius);
}

tower_t *my_add_tower(tower_t *list, char *str, sfTexture *texture)
{
	tower_t *new = malloc(sizeof(*new));
	int total = my_count_nb_arg(str);

	if (total != 3){
		free(new);
		return (NULL);
	}
	fill_new_tower(new, str, texture);
	new->next = list;
	list = new;
	return (list);
}

tower_t *init_towers(char *str)
{
	tower_t *towers = NULL;
	sfTexture *texture = sfTexture_createFromFile("satellite.png", NULL);
	int i = 0;
	int total;

	total = my_count_nb_line(str);
	while (i != total) {
		if (str[0] == 'T')
			towers = my_add_tower(towers, str, texture);
		str += my_find_len_line(str);
		i++;
	}
	return (towers);
}
