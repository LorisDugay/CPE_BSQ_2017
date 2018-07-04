/*
** EPITECH PROJECT, 2018
** BSQ.h
** File description:
** made by Loris D
*/

#ifndef __BSQ_h__
#define __BSQ_h__
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct square_s
{
	int x;
	int y;
	int max;
}square_t;

void val(square_t *geo, square_t *ordo, int index);
void algo(char *tab, int column, int line, int index);
void stock(char *tab, char **av, struct stat *size);
int columns(char **av);
int lines(char *buffer, char **av);
int size_square(square_t *absc, int column, int *ind, char *tab);
int write_x(int column, char *tab, square_t *absc);

#endif /* __BSQ_h__ */
