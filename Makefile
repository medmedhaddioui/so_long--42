NAME = so_long

NAME_BONUS = so_long_bonus

SRC = ./Mandatory/so_long.c ./Mandatory/parsing.c ./Mandatory/utils.c \
		./Mandatory/window.c ./Mandatory/movements.c ./Mandatory/parsing2.c

SRC_BONUS = ./Bonus/so_long_bonus.c ./Bonus/parsing_bonus.c ./Bonus/utils_bonus.c \
  		./Bonus/window_bonus.c ./Bonus/movements_bonus.c ./Bonus/parsing2_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx -g3 -fsanitize=address

LDFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT_A = libft/libft.a

all : $(NAME)

$(NAME): $(SRC)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRC)  $(LIBFT_A) $(LDFLAGS) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(SRC_BONUS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRC_BONUS)  $(LIBFT_A) $(LDFLAGS) -o $(NAME_BONUS)

clean:
	cd libft && rm -rf *.o
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	cd libft && rm -rf libft.a

re: fclean all

.PHONY: all clean fclean re bonus