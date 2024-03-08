NAME		=	push_swap
BONUS		=	checker
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRC			=	src/algorithms/move_a_to_b.c\
				src/algorithms/sort_stack.c\
				src/algorithms/sort_three.c\
				src/freeerrors/free_list.c\
				src/freeerrors/free_tab.c\
				src/freeerrors/ft_error.c\
				src/freeerrors/handle_error.c\
				src/init/init_node_a.c\
				src/init/init_node_b.c\
				src/init/init_with_split.c\
				src/init/init_without_split.c\
				src/init/set_index.c\
				src/list_functions/create_list.c\
				src/list_functions/ps_lstadd_back.c\
				src/list_functions/ps_lstlast.c\
				src/list_functions/ps_lstnew.c\
				src/parsing/check_for_occurence.c\
				src/parsing/is_int.c\
				src/parsing/tab_is_digit.c\
				src/push_swap_functions/pa.c\
				src/push_swap_functions/pb.c\
				src/push_swap_functions/ra.c\
				src/push_swap_functions/rb.c\
				src/push_swap_functions/rr.c\
				src/push_swap_functions/rra.c\
				src/push_swap_functions/rrb.c\
				src/push_swap_functions/rrr.c\
				src/push_swap_functions/sa.c\
				src/push_swap_functions/sb.c\
				src/push_swap.c\
				src/utils.c

SRC_BONUS	=	bonus/checker_utils.c\
				bonus/checker.c\
				src/algorithms/move_a_to_b.c\
				src/algorithms/sort_stack.c\
				src/algorithms/sort_three.c\
				src/freeerrors/free_list.c\
				src/freeerrors/free_tab.c\
				src/freeerrors/ft_error.c\
				src/freeerrors/handle_error.c\
				src/init/init_node_a.c\
				src/init/init_node_b.c\
				src/init/init_with_split.c\
				src/init/init_without_split.c\
				src/init/set_index.c\
				src/list_functions/create_list.c\
				src/list_functions/ps_lstadd_back.c\
				src/list_functions/ps_lstlast.c\
				src/list_functions/ps_lstnew.c\
				src/parsing/check_for_occurence.c\
				src/parsing/is_int.c\
				src/parsing/tab_is_digit.c\
				src/push_swap_functions/pa.c\
				src/push_swap_functions/pb.c\
				src/push_swap_functions/ra.c\
				src/push_swap_functions/rb.c\
				src/push_swap_functions/rr.c\
				src/push_swap_functions/rra.c\
				src/push_swap_functions/rrb.c\
				src/push_swap_functions/rrr.c\
				src/push_swap_functions/sa.c\
				src/push_swap_functions/sb.c\
				src/utils.c

OBJ 		=	${SRC:.c=.o}
OBJ_BONUS 	=	${SRC_BONUS:.c=.o}
MAKE_LIBFT	=	@make -C libft
LIBFT		=	libft/libft.a


all: $(NAME)

bonus:	$(NAME) $(BONUS)

$(NAME): $(SRC) $(OBJ)
	$(MAKE_LIBFT)
	$(MAKE_LIBFT) bonus
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(BONUS): $(SRC_BONUS) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(BONUS)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
	$(MAKE_LIBFT) clean

fclean:	clean
	rm -rf $(NAME) $(BONUS)
	$(MAKE_LIBFT) fclean

re : fclean all

.PHONY: all, clean, fclean, re