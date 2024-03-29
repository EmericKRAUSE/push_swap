/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:07:15 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/07 14:29:42 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stack **a, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (count_stack(*a) < 2)
		return ;
	first = *a;
	last = ps_lstlast(*a);
	*a = (*a)->next;
	(*a)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	if (print)
		ft_putendl_fd("ra", 1);
}
