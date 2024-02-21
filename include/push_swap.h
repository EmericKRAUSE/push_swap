/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:31:18 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/21 11:09:24 by ekrause          ###   ########.fr       */
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
}					t_stack;

//**********/
//UTILS
int	count_stack(t_stack *stack);
void	swap(t_stack **stack);
void	push(t_stack **stack1, t_stack **stack2);

//**********/
//ERROR
void	handle_error(t_stack **a, char ***numbers);
void	ft_error(void);

//**********/
//FREE
void	free_tab(char ***tab);
void	free_list(t_stack **stack);

#endif