/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:46:38 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/22 13:38:28 by ekrause          ###   ########.fr       */
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
	if (*stack2)
		(*stack2)->prev = NULL;
	if (!*stack1)
	{
		*stack1 = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *stack1;
		(*stack1)->prev = temp;
		*stack1 = temp;
	}
}