/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:46:38 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/21 10:27:40 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack *temp;
	
	if (!*stack2)
		return ;
	temp = *stack2;
	*stack2 = (*stack2)->next;
	if (!*stack1)
		*stack1 = temp;
	else
	{
		temp->next = *stack1;
		(*stack1)->prev = temp;
		*stack1 = temp;
	}
}