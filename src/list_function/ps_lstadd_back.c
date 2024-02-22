/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:11:52 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/22 13:38:28 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ps_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack != NULL && new != NULL)
	{
		if (*stack == NULL)
			*stack = new;
		else
		{
			last = ps_lstlast(*stack);
			last->next = new;
			new->prev = last;
		}
	}
}
