NAME = game_2048

OBJ = main.o \
	  display.o \
	  test.o \
	  init_color.o \
	  win.o

LIB = libft

CC = gcc -g -Wall -Wextra -Werror -I $(LIB)

all: lib $(NAME)

lib:
	make -C $(LIB)

$(NAME): $(OBJ) game.h
	$(CC) -o $(NAME) $(OBJ) -lncurses $(LIB)/libft.a

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re: fclean all

.PHONY: clean all re fclean
