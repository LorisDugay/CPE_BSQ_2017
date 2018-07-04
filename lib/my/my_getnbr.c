/*
** EPITECH PROJECT, 2018
** getnbr
** File description:
** made by Loris D
*/

#include <stdlib.h>

int my_getnbr(char const *str)
{
	int i = 0;
	int nb = 0;
	int nega = 1;

	while (str[i] != '\0') {
		while (str[i] == '-' || str[i] == '+') {
			if (str[i] == '-')
				nega = -nega;
			i = i + 1;
		}
		while (str[i] >= '0' && str[i] <= '9') {
			nb = nb * 10;
			nb = nb + (str[i] - '0');
			i = i + 1;
		}
		nb = nb *nega;
		if (str[i] > '0' || str[i] > '9')
			return (nb);
	}
	return (nb);
}
