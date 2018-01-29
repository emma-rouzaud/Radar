/*
** EPITECH PROJECT, 2018
** trajectory.c
** File description:
** radar
*/

#include "include.h"

int my_check_time(int t1, int t2)
{
	if (t1 < t2 + 1 && t1 > t2 - 1)
		return (1);
	return (0);
}

double my_find_intersection(plane_t *plane, double a, double b, double *y)
{
	double m;
	double p;

	m = (plane->init.y - plane->fin.y == 0 ? 1 :\
	 plane->init.y - plane->fin.y) / (plane->init.x - plane->fin.x \
	== 0 ? 1 : plane->init.x - plane->fin.x);
	p = plane->pos.y - plane->pos.x * m;
	*y = a * ((- p + b) / (m - a)) + b;
	return ((- p + b) / (m - a));
}

int my_check_col(plane_t *plane)
{
	sfVector2f tmp = plane->pos;
	int speed = plane->speed;
	double a = (plane->init.y - plane->fin.y == 0 ? 1 :\
	plane->init.y - plane->fin.y) / (plane->init.x - plane->fin.x\
	== 0 ? 1 : plane->init.x - plane->fin.x);
	double b = plane->pos.y - plane->pos.x * a;
	double x;
	double y;
	double t1;
	double t2;
	int i = 0;

	while (plane->next != NULL) {
		plane = plane->next;
		x = my_find_intersection(plane, a, b, &y);
		t2 = sqrt(pow(plane->pos.x - x, 2) + pow(plane->pos.y\
		- y, 2)) / plane->speed;
		t1 = sqrt(pow(tmp.x - x, 2) + pow(tmp.y - y, 2)) / speed;
		i += my_check_time(t1, t2);
	}
	if (i >= 1)
		return (1);
	return (0);
}

void my_check_pos(plane_t *plane, tower_t *tower)
{
	int hit = 0;

	if ((pow(plane->pos.x - tower->pos.x, 2) + pow(plane->pos.y - \
		tower->pos.y, 2)) <= pow(tower->radius, 2)){
		hit = my_check_col(plane);
		if (hit == 1)
			plane->speed += 10;
	}
}

void my_prevent_col(plane_t *plane, tower_t *tower)
{
	while (tower != NULL) {
		while (plane != NULL) {
			my_check_pos(plane, tower);
			plane = plane->next;
		}
		tower = tower->next;
	}
}
