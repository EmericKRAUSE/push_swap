/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:59:40 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/07 14:30:53 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack **a, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (count_stack(*a) < 2)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (first->next != NULL)
		first->next->prev = first;
	*a = second;
	if (print)
		ft_putendl_fd("sa", 1);
}
