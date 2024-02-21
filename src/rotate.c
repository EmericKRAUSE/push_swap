/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:07:15 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/21 13:58:32 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack *temp;
	t_stack *last;

	if (count_stack(*stack) < 2)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last = ps_lstlast(*stack);
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
}