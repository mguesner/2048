NAME = game_2048

OBJ = main.o \
	  display.o \
	  test.o

CC = gcc -g -Wall -Wextra -Werror

all: $(NAME)

lib:
	make -C $(LIB)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lncurses

%.o: %.c 
	$(CC) -o $@ -c $<

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re: fclean all

.PHONY: clean all re fclean