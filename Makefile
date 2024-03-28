NAME = so_long

SRC = so_long.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

all : $(NAME)

$(NAME): $(SRC)
	cd libft && $(MAKE)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT_A) -o $(NAME) $(LDFLAGS)

clean:
	cd libft && rm -rf *.o
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)
	cd libft && rm -rf libft.a

re: fclean all

.PHONY: all clean fclean re