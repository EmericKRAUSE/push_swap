/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:49:53 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/29 10:50:13 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rrb(t_stack **b)
{
	t_stack *last;

	if (count_stack(*b) < 2)
		return ;
	last = ps_lstlast(*b);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *b;
	(*b)->prev = last;
	*b = last;
	ft_putendl_fd("rrb", 1);
}