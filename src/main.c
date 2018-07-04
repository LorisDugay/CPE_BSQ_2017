/*
** EPITECH PROJECT, 2018
** read_square
** File description:
** made by loris D
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/BSQ.h"

int columns(char **av)
{
	int fd = open(av[1], O_RDONLY);
	int x = 0;
	int size = 1;
	char buffer[2];

	buffer[0] = 0;
	buffer[1] = '\0';
	while (size != 0 && buffer[0] != '\n')
		size = read(fd, buffer, 1);
	buffer[0] = 0;
	while (buffer[0] != '\n' && size != 0) {
		size = read(fd, buffer, 1);
		x = x + 1;
	}
	close(fd);
	return (x);
}

int lines(char *buffer, char **av)
{
	int fd = open(av[1], O_RDONLY);
	int incr = 0;
	int get_line = 0;
	char get_lines[15];

	read(fd, buffer, 15);
	while (buffer[incr] != '\n') {
		get_lines[incr] = buffer[incr];
		incr = incr + 1;
	}
	get_lines[incr] = '\0';
	get_line = my_getnbr(get_lines);
	close(fd);
	return (get_line);
}

void stock(char *tab, char **av, struct stat *size)
{
	int fd = open(av[1], O_RDONLY);
	char incr = 0;
	char buffer[2];

	buffer[0] = 0;
	buffer[1] = '\0';
	while (buffer[0] != '\n') {
		read(fd, buffer, 1);
		buffer[1] = '\0';
		incr = incr + 1;
	}
	read(fd, tab, size->st_size - incr);
	tab[size->st_size - incr] = '\0';
	close(fd);
}

int main(int ac, char **av)
{
	struct stat size;

	int df = stat(av[1], &size);
	char *tab = malloc(size.st_size);
	char buffer[512];
	int index = 0;
	int column = 0;
	int line = 0;

	if (df == -1)
		return (84);
	if (tab == NULL)
		return (84);
	if ((column = columns(av)) == 1);
	if ((line = lines(buffer, av)) == 1)
		return (0);
	stock(tab, av, &size);
	algo(tab, column, line, index);
	my_putstr(tab);
	free(tab);
	return (0);
}
