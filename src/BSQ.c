/*
** EPITECH PROJECT, 2018
** square
** File description:
** made by Loris D
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/BSQ.h"

void val(square_t *geo, square_t *ordo, int index)
{
	geo->max = 0;
	ordo->max = 0;
	geo->x = index;
	ordo->x = index;
	geo->y = 0;
	ordo->y = 0;
}

int size_square(square_t *absc, int column, int *ind, char *tab)
{
	absc->x = 0;
	absc->max = 0;
	int x = *ind;
	int y = *ind;
	int save_x = x;
	int save_y = y;
	int k = 0;
	int whille = 0;
	int detek = 0;

	while (tab[save_x] && tab[save_y] && detek == 0) {
		k = k + 1;
		x = x + 1;
		y = y + column;
		save_x = x;
		save_y = y;
		while (tab[save_x] && whille <= k && detek == 0) {
			if (tab[save_x] != '.')
				detek++;
			whille = whille + 1;
			save_x = save_x + column;
		}
		whille = 0;
		while (tab[save_y] && whille <= k && detek == 0) {
			if (tab[save_y] != '.')
				detek++;
			whille = whille + 1;
			save_y = save_y + 1;
		}
		whille = 0;
	}
	if (detek != 0)
		k = k - 1;
	absc->max = k;
	absc->x = *ind;
	return (0);
}

int write_x(int column, char *tab, square_t *absc)
{
	int x = 0;
	int y = 0;

	if (absc->max == 0)
		return (0);
	while (y <= absc->max) {
		while (x <= absc->max) {
			tab[absc->x] = 'x';
			absc->x++;
			x = x + 1;
		}
		absc->x = absc->x + column - absc->max - 1;
		x = 0;
		y = y + 1;
	}
	return (0);
}

void is_bigger(square_t *geo, square_t *ordo, int column, char *tab)
{
	int ind = geo->x;

	while (tab[ind]) {
		if (tab[ind] == '.') {
			size_square(ordo, column, &ind, tab);
			if (ordo->max > geo->max) {
				geo->max = ordo->max;
				geo->x = ordo->x;
			}
		}
		ind = ind + 1;
	}
	write_x(column, tab, geo);
}

void algo(char *tab, int column, int line, int index)
{
	square_t geo;
	square_t ordo;

	val(&geo, &ordo, index);
	is_bigger(&geo, &ordo, column, tab);
}
