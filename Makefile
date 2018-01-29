##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	./src/main.c			\
		./src/event.c			\
		./src/collision_p.c		\
		./src/collision_z.c		\
		./src/line.c			\
		./src/destroy.c			\
		./src/ctx.c			\
		./src/trajectory.c		\
		./src/load/my_getnbr.c		\
		./src/load/my_putstr.c		\
		./src/load/plane.c		\
		./src/load/tower.c		\
		./src/load/zone.c		\
		./src/load/my_strlen.c		\
		./src/load/loadfile.c		\
		./src/load/check_tab.c		\
		./src/display/disp_plane.c	\
		./src/display/disp_tower.c	\
		./src/display/disp_usage.c	\
		./src/display/disp_zone.c	\
		./src/display/disp_map.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I./include/

NAME	=	my_radar

all: 	$(NAME) clean

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lm $(CFLAGS) -lc_graph_prog

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all

my:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lm $(CFLAGS) -l csfml-graphics -l csfml-system
	make clean
