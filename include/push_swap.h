/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:31:18 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/08 15:58:14 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

//**********/
//ALGORITHMS
void	move_a_to_b(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);

//**********/
//ERRORS & FREE
void	free_list(t_stack **stack);
void	free_tab(char ***tab);
void	ft_error(void);
void	handle_error(t_stack **a, char ***numbers);

//**********/
//INIT
void	init_node_a(t_stack *a, t_stack *b);
void	init_node_b(t_stack *a, t_stack *b);
void	init_with_split(char ***argv, t_stack **a);
void	init_without_split(char ***argv, t_stack **a);
void	set_index(t_stack *stack);

//**********/
//LIST FUNCTIONS
void	create_list(char **tab, t_stack **stack);
void	ps_lstadd_back(t_stack **stack, t_stack *new);
t_stack	*ps_lstlast(t_stack *stack);
t_stack	*ps_lstnew(char *content);

//**********/
//PARSING
int		check_for_occurrence(t_stack *stack);
int		is_int(char **tab);
int		tab_is_digit(char **tab);

//**********/
//PUSH SWAP
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **b, t_stack **a, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);

//**********/
//UTILS
void	prep_to_push(t_stack **stack, t_stack *to_rotate, char stack_name);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
int		is_sorted(t_stack *stack);
int		count_stack(t_stack *stack);
int		ft_strcmp(char *s1, char *s2);

#endif