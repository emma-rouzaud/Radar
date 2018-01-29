/*
** EPITECH PROJECT, 2017
** check_tab.c
** File description:
** radar
*/

int my_find_len_line(char *str)
{
	int i = 0;
	int count = 1;

	if (str[i] == '\n') {
		count += 2;
		i++;
	}
	while (str[i] != '\n' && str[i] != '\0') {
		i++;
		count++;
	}
	return (count);
}

int my_count_nb_arg(char *str)
{
	int i = 0;
	int space = 0;

	while (str[i] != '\n' && str[i] != '\0') {
		if (str[i] == ' ')
		space++;
		i++;
	}
	return (space);
}

int my_count_nb_line(char *str)
{
	int i = 0;
	int enter = 1;

	while (str[i] != '\0') {
		if (str[i] == '\n')
			enter++;
		i++;
	}
	return (enter);
}
