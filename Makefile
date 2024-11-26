##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile
##

pathdir = src/lib


NAME = libmy.a
EXEC = my_ls



SRC	=	src/open_window.c \
		$(pathdir)/my_compute_power_rec.c \
		$(pathdir)/my_compute_square_root.c \
		$(pathdir)/my_isneg.c \
		$(pathdir)/my_put_nbr.c \
		$(pathdir)/my_putchar.c \
		$(pathdir)/my_putstr.c \
		$(pathdir)/my_revstr.c \
		$(pathdir)/my_strcat.c \
		$(pathdir)/my_strcpy.c \
		$(pathdir)/my_strlen.c \
		$(pathdir)/my_strncat.c \
		$(pathdir)/my_strncpy.c \
		$(pathdir)/flag_c.c \
		$(pathdir)/flag_d.c \
		$(pathdir)/flag_i.c \
		$(pathdir)/flag_o.c \
		$(pathdir)/flag_percent.c \
		$(pathdir)/flag_s.c \
		$(pathdir)/flag_x.c \
		$(pathdir)/flag_x2.c \
		$(pathdir)/my_printf.c \

OBJ  	=	 $(SRC:.c=.o)

LIB_OBJ =  $(LIB:.c=.o)


$(NAME):	$(LIB_OBJ)
		ar rcs $(NAME) $(LIB_OBJ)
		$(MAKE) clean
		gcc -g $(SRC) -Iinclude -L. -lmy -o $(EXEC)

$(EXEC): $(OBJ) $(NAME)
		gcc -o $(EXEC) $(OBJ) -Iinclude -L -libmy

all: 	$(NAME) $(EXEC)



clean:
		rm -f $(OBJ) $(LIB_OBJ)


fclean: clean
		rm -f $(NAME) $(TEST) $(OBJ)ç

re:
		$(MAKE) fclean
		$(MAKE) all
debug:
		$(MAKE) clean
		gcc -g $(SRC) -Iinclude -L. -lmy -o $(EXEC)
