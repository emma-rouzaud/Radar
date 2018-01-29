/*
** EPITECH PROJECT, 2017
** mu_radar.h
** File description:
** radar
*/

#ifndef _FRAMEBUFFER_H_
#define _FRAMEBUFFER_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct framebuffer {
	unsigned int width;
	unsigned int height;
	sfUint8		*pixels;
}framebuffer_t;

typedef struct context {
	int width;
	int height;
	sfVideoMode mode;
	sfRenderWindow *window;
	sfTexture *texture;
	sfSprite *sprite;
	framebuffer_t *buffer;
	unsigned int size;
	int disp_sprite;
	int disp_hitbox;
}ctx_t;

typedef struct plane_s {
	sfRectangleShape *hitbox;
	sfRectangleShape *rect;
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f init;
	sfVector2f fin;
	int speed;
	float delay;
	sfVector2f pos;
	float x;
	int hit;
	double a;
	double b;
	struct plane_s *next;
}plane_t;

typedef struct tower_s {
	sfSprite *sprite;
	sfTexture *texture;
	sfRectangleShape *rect;
	sfCircleShape *hitbox;
	sfVector2f pos;
	int radius;
	struct tower_s *next;
}tower_t;

typedef struct zone_s {
	sfTexture *texture;
	sfConvexShape *shape;
	sfConvexShape *hitbox;
	struct zone_s *next;
}zone_t;

int my_putstr(char const *str);
void my_radar(ctx_t *ctx);
void my_check_event(ctx_t *ctx);
unsigned int my_get_value(char const *str, int *i);
plane_t *init_planes(char *filepath);
char *my_load_file(char *filepath);
int my_find_len_line(char *str);
int my_count_nb_arg(char *str);
int my_count_nb_line(char *str);
void my_draw_line(plane_t *plane, ctx_t *ctx);
void my_manage_delay(plane_t *plane);
int my_check_collision_plane(plane_t *plane);
void my_move_i(char *str, int *i);
void my_disp_plane(ctx_t *ctx, plane_t *plane);
void my_disp_tower(ctx_t *ctx, tower_t *tower);
tower_t *init_towers(char *str);
void my_disp_map(ctx_t *ctx);
void my_prevent_col(plane_t *plane, tower_t *tower);
void my_destroy_structs(plane_t *, tower_t *, zone_t *);
sfRectangleShape *my_create_rect(sfColor color);
void my_disp_usage(void);
zone_t *init_zone(char *str);
void my_disp_zone(ctx_t *ctx, zone_t *zone);
void my_check_collision_zone(plane_t *plane, zone_t *zone);
int my_check_end(plane_t *plane);
void init_ctx(ctx_t *ctx);

#endif
