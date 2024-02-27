/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:31:18 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/27 11:31:36 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				content;
	int				index;
}					t_stack;

//**********/
//PUSH SWAP
void	swap(t_stack **stack);
void	push(t_stack **stack1, t_stack **stack2);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

//**********/
//LIST FUNCTIONS
void	create_a_list(char **tab, t_stack **stack);
void	print_list(t_stack *stack);
void	ps_lstadd_back(t_stack **stack, t_stack *new);
t_stack	*ps_lstlast(t_stack *stack);
t_stack	*ps_lstnew(char *content);
void	reverse_print_list(t_stack *stack);

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