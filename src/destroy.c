/*
** EPITECH PROJECT, 2017
** line.c
** File description:
** radar
*/

#include "include.h"

void my_destroy_plane(plane_t *plane)
{
	plane_t *ptr;

	while (plane != NULL) {
		ptr = plane;
		plane = plane->next;
		free(ptr);
	}
}

void my_destroy_tower(tower_t *tower)
{
	tower_t *ptr;

	while (tower != NULL) {
		ptr = tower;
		tower = tower->next;
		free(ptr);
	}
}

void my_destroy_zone(zone_t *zone)
{
	zone_t *ptr;

	while (zone != NULL) {
		ptr = zone;
		zone = zone->next;
		free(ptr);
	}
}

void my_destroy_structs(plane_t *plane, tower_t *tower, zone_t *zone)
{
	my_destroy_plane(plane);
	if (tower != NULL)
		my_destroy_tower(tower);
	if (zone != NULL)
		my_destroy_zone(zone);
}
