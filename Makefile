##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## made by Loris D
##

CC	=	gcc

SRC	=	src/BSQ.c	\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

CFLAGS	=	-Wall

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) -Llib/my -lmy

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean

re:	fclean all
	make -C lib/my re
