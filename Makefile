NAME		=	push_swap
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRC			=	src/push_swap.c\
				src/swap.c\
				src/push.c\
				src/utils.c

OBJ 		=	${SRC:.c=.o}
MAKE_LIBFT	=	@make -C libft
LIBFT		=	libft/libft.a


all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	$(MAKE_LIBFT)
	$(MAKE_LIBFT) bonus
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	./$(NAME) "1 2 3 4 5 6 7 8 9 10" | cat -e

clean:
	rm -rf $(OBJ)
	$(MAKE_LIBFT) clean

fclean:	clean
	rm -rf $(NAME)
	$(MAKE_LIBFT) fclean

re : fclean all

.PHONY: all, clean, fclean, re