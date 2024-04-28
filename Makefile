NAME = so_long

SRC = ./Mandatory/so_long.c ./Mandatory/parsing.c ./Mandatory/utils.c \
		./Mandatory/window.c ./Mandatory/movements.c ./Mandatory/parsing2.c \
		./Mandatory/move_player.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT_A = libft/libft.a

all : $(NAME)

$(NAME): $(SRC)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRC) $(LIBFT_A) $(LDFLAGS) -o $(NAME)

clean:
	cd libft && rm -rf *.o
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	cd libft && rm -rf libft.a

re: fclean all

.PHONY: all clean fclean re
