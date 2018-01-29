/*
** EPITECH PROJECT, 2017
** lodafile.c
** File description:
** radar
*/

#include "include.h"

char	*my_fs_cat_x_bytes(int fd, int x)
{
	char *str = malloc(sizeof(char) * x + 1);

	str[x] = '\0';
	if (!(read(fd, str, x)))
		return (NULL);
	return (str);
}

char *my_load_file(char *filepath)
{
	int fd = open(filepath, O_RDONLY);
	int i = 0;
	char *str;
	char buffer[256];

	if (fd == -1)
		return (NULL);
	while (read(fd, buffer, 1))
		i += 1;
	close(fd);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = my_fs_cat_x_bytes(fd, i);
	if (str == NULL)
		return (NULL);
	close(fd);
	return (str);
}
