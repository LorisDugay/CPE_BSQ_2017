/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** Made by Loris D
*/

#ifndef __my_h__
#define __my_h__
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void my_putchar(char c);
void my_putstr(char const *str);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);

#endif /* __my_h__ */
