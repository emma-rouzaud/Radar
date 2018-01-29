/*
** EPITECH PROJECT, 2017
** collision.c
** File description:
** radar
*/

#include "include.h"

int my_check_point_in_box(plane_t *plane, float pt_x, float pt_y)
{
	if (pt_x - plane->pos.x >= 0 && pt_x - plane->pos.x - 20 <= 0 &&\
	pt_y - plane->pos.y >= 0 && pt_y - plane->pos.y - 20 <= 0 ) {
		return (1);
	}
	return (0);
}

int my_check_collision_plane(plane_t *plane)
{
	float x = plane->pos.x;
	float y = plane->pos.y;
	int hit = 0;

	while (plane->next != NULL) {
		plane = plane->next;
		hit += my_check_point_in_box(plane, x, y);
		hit += my_check_point_in_box(plane, x + 20, y);
		hit += my_check_point_in_box(plane, x, y + 20);
		hit += my_check_point_in_box(plane, x + 20, y + 20);
		if (hit >= 1) {
			plane->hit = 1;
			plane->pos.y = plane->fin.y;
			return (1);
		}
	}
	return (0);
}
