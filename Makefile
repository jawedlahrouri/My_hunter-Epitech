##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile
##

SRC	=	src/my_hunter.c \
		src/window.c \
		src/sprite.c \
		src/event.c \
		src/move_duck.c \

OBJ  	=	 $(SRC:.c=.o)

HUNTER = my_hunter

CFLAGS = -Iinclude -lcsfml-graphics -lcsfml-window -lcsfml-audio \
		-lcsfml-network -lcsfml-system

$(HUNTER): $(OBJ)
		gcc $(OBJ) -o $(HUNTER) $(CFLAGS)

all: 	$(HUNTER)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(HUNTER)

re:
		$(MAKE) fclean
		$(MAKE) all

debug:
		$(MAKE) clean
		gcc -g $(SRC) -o $(HUNTER) $(CFLAGS) 
