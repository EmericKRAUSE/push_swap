/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:39:56 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/08 10:30:51 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pb(t_stack **b, t_stack **a, int print)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	if (!*b)
	{
		*b = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *b;
		(*b)->prev = temp;
		*b = temp;
	}
	if (print)
		ft_putendl_fd("pb", 1);
}
