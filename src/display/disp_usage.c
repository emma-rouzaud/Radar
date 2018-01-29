/*
** EPITECH PROJECT, 2018
** disp_usage.c
** File description:
** radar
*/

#include "include.h"

void my_disp_usage(void)
{
	my_putstr("Air traffic simulation panel\nUSAGE:\n  ./my_radar ");
	my_putstr("[OPTIONS] path to script\n  path to script	The ");
	my_putstr("path to the script file.\n\nOPTIONS\n  -h		");
	my_putstr("	print the usage and quit.\n\nUSER INTERACTIONS\n  ");
	my_putstr("'L' key 		enable/disable hitboxes of planes");
	my_putstr(", towers and areas.\n  'S' key		enable/");
	my_putstr("disable sprites.\n\n");
}
