NAME = game_2048

OBJ = main.o \
	  display.o \
	  init_color.o \
	  win.o \
	  play.o \
	  init.o \
	  save.o \
	  right.o\
	  up.o \
	  leftt.o \
	  down.o \
	  update.o\
	  generate.o \
	  check_enum.o \
	  end.o \
	  reset.o

LIB = libft

CC = gcc -g -Wall -Wextra -Werror -I $(LIB)

all: lib $(NAME)

lib:
	make -C $(LIB)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lncurses $(LIB)/libft.a

%.o: %.c game.h
	$(CC) -o $@ -c $<

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re: fclean all

.PHONY: clean all re fclean
