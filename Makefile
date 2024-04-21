NAME = so_long

SRC = so_long.c parsing.c utils.c parsing2.c  window.c movements.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx -g3 -fsanitize=address

LDFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT_A = libft/libft.a

all : $(NAME)

$(NAME): $(SRC)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRC)  $(LIBFT_A) $(LDFLAGS) -o $(NAME) 

clean:
	cd libft && rm -rf *.o
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)
	cd libft && rm -rf libft.a

re: fclean all

.PHONY: all clean fclean re