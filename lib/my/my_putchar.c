/*
** EPITECH PROJECT, 2017
** my_putchar
** File description:
** fonction my_putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
	write (1, &c, 1);
}
