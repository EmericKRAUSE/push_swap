/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:29:50 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/07 14:30:10 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack **a, int print)
{
	t_stack	*last;

	if (count_stack(*a) < 2)
		return ;
	last = ps_lstlast(*a);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *a;
	(*a)->prev = last;
	*a = last;
	if (print)
		ft_putendl_fd("rra", 1);
}
