##
## Makefile for Makefile in /home/thibrex/delivery/CPool_Day10/do-op
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Sat Oct 15 22:12:03 2016 Thibaut Cornolti
## Last update Thu Feb  2 16:19:11 2017 Thibaut Cornolti
##
SRC	=	main.c		\
		parser.c	\
		utils.c		\
		utils2.c	\
		fct_free.c	\
		check_map.c	\
		shower.c	\
		server.c	\
		client.c	\
		receive.c	\
		send.c		\
		win_cond.c	\
		game.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	navy

CC	=	gcc -g

HEADER	=	include/

RM	=	rm -f

LIB_P	=	-Llib/my

LIB	=	-lmy

all:	$(NAME)

$(NAME):
	cd lib/my/ && make
	$(CC) -o $(NAME) -I$(HEADER) $(SRC) $(LIB_P) $(LIB) -Wall -Wextra -pedantic

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
