NAME = so_long

SRC =	so_long.c

OBJECT = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
LIBFT_A = libft/libft.a

all : $(NAME)

$(NAME): $(SRC)
	cd libft && $(MAKE)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT_A) -o $(NAME)

clean:
	cd libft && rm -rf *.o
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)
	cd libft && rm -rf libft.a

re: fclean all

.PHONY: all clean fclean re