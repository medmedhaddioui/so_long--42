NAME = so_long

SRC = so_long.c parsing.c utils.c parsing2.c 

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror  

LIBFT_A = libft/libft.a

all : $(NAME)

$(NAME): $(SRC)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRC)  $(LIBFT_A) -o $(NAME)

clean:
	cd libft && rm -rf *.o
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)
	cd libft && rm -rf libft.a

re: fclean all

.PHONY: all clean fclean re