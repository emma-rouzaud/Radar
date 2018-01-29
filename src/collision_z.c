/*
** EPITECH PROJECT, 2017
** collision.c
** File description:
** radar
*/

#include "include.h"

int my_check_direction(zone_t *zone, int count)
{
	sfVector2f pos1;
	sfVector2f pos2;
	double a;
	int i = 0;

	while (i < count - 1) {
		pos1 = sfConvexShape_getPoint(zone->shape, i);
		pos2 = sfConvexShape_getPoint(zone->shape, i + 1);
		a += (pos1.x * pos2.y) - (pos2.x * pos1.y);
		i++;
	}
	if (a > 0)
		return (0);
	else
		return (1);
}

int my_check_point_side(sfVector2f pos1, sfVector2f pos2, \
	 sfVector2f plane, int direction)
{
	sfVector2f D = {pos2.x - pos1.x, pos2.y - pos1.y};
	sfVector2f T = {plane.x - pos1.x, plane.y - pos1.y};
	float d = (D.x * T.y) - (D.y * T.x);

	if ((d >= 0 && direction == 0) || (d <= 0 && direction == 1)) {
		return (1);
	}
	return (0);
}

void my_detect_col(sfVector2f pt_pos, zone_t *zone, int dir, plane_t *plane)
{
	sfVector2f pos1;
	sfVector2f pos2;
	int count;
	int hit = 0;
	int i = 0;

	count = sfConvexShape_getPointCount(zone->shape);
	while (i < count) {
		pos1 = sfConvexShape_getPoint(zone->shape, i);
		pos2 = (i + 1 == count) ? sfConvexShape_getPoint(\
zone->shape, 0) : sfConvexShape_getPoint(zone->shape, i + 1);
		hit += my_check_point_side(pos1, pos2, pt_pos, dir);
		i++;
	}
	if (hit == count)
		plane->hit = 1;
}

void my_check_list(plane_t *plane, zone_t *zone, int direction)
{
	while (plane != NULL) {
		my_detect_col((sfVector2f){plane->pos.x, plane->pos.y}, \
		zone, direction, plane);
		my_detect_col((sfVector2f){plane->pos.x + 20, plane->pos.y}, \
		zone, direction, plane);
		my_detect_col((sfVector2f){plane->pos.x + 20, plane->pos.y + \
		20}, zone, direction, plane);
		my_detect_col((sfVector2f){plane->pos.x, plane->pos.y + 20}, \
		zone, direction, plane);
		plane = plane->next;
	}
}

void my_check_collision_zone(plane_t *plane, zone_t *zone)
{
	int direction;

	while (zone != NULL) {
		direction = my_check_direction(zone, \
			 sfConvexShape_getPointCount(zone->shape));
		if (direction == 84)
			return;
		else
			my_check_list(plane, zone, direction);
		zone = zone->next;
	}
}
