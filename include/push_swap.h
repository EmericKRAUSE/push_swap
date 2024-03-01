/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:31:18 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/01 13:11:30 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

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
void	sort_three(t_stack **a);

//**********/
//INIT
void	init_with_split(char ***argv, t_stack **a);
void	init_without_split(char ***argv, t_stack **a);

//**********/
//LIST FUNCTIONS
void	create_list(char **tab, t_stack **stack);
void	print_list(t_stack *stack);
void	ps_lstadd_back(t_stack **stack, t_stack *new);
t_stack	*ps_lstlast(t_stack *stack);
t_stack	*ps_lstnew(char *content);
void	reverse_print_list(t_stack *stack);

//**********/
//PARSING
int	check_for_occurrence(t_stack *stack);
int	is_int(char **tab);
int	tab_is_digit(char **tab);

//**********/
//PUSH SWAP
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ra(t_stack **a, int	rr);
void	rb(t_stack **b, int rr);
void	rra(t_stack **a, int rrr);
void	rrb(t_stack **b, int rrr);
void	sa(t_stack **a);
void	sb(t_stack **b);


//**********/
//UTILS
int	count_stack(t_stack *stack);

//**********/
//ERROR
void	handle_error(t_stack **a, char ***numbers);
void	ft_error(void);

//**********/
//FREE
void	free_tab(char ***tab);
void	free_list(t_stack **stack);

#endif