##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## made by Loris D
##

SRC	=	my_putchar.c	\
		my_put_nbr.c	\
		my_strlen.c	\
		my_putstr.c	\
		my_getnbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
