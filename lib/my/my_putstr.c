/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** fonction my_putstr
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"

void my_putstr(char const *str)
{
	int	i = my_strlen(str);

	write(1, str, i);
}
