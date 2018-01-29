/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** task03
*/

int	my_strlen(char const *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

void my_move_i(char *str, int *i)
{
	while (str[*i] != ' ')
		*i += 1;
}
