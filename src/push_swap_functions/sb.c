/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:18:09 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/07 14:31:14 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sb(t_stack **b, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (count_stack(*b) < 2)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (first->next != NULL)
		first->next->prev = first;
	*b = second;
	if (print)
		ft_putendl_fd("sb", 1);
}
