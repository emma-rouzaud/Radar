/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** lib
*/

int	my_get_value(char const *str, int i)
{
	int nb = 0;

	while (str[i] <= '9' && str[i] >= '0') {
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb);
}

int	my_getnbr(char const *str, int *i)
{
	int nb = 0;

	while (str[*i] != '\0') {
		if (str[*i] >= '0' && str[*i] <= '9') {
			nb = my_get_value(str, *i);
			return (nb);
		}
		*i += 1;
	}
	return (nb);
}
