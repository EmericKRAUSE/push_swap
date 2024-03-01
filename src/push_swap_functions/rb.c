/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:48:20 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/01 13:03:01 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rb(t_stack **b, int rr)
{
	t_stack *first;
	t_stack *last;

	if (count_stack(*b) < 2)
		return ;
	first = *b;
	last = ps_lstlast(*b);
	*b = (*b)->next;
	(*b)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	if (!rr)
		ft_putendl_fd("rb", 1);
}