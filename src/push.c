/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:46:38 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/20 21:04:58 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack *temp;
	
	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	if (!*a)
		*a = temp;
	else
	{
		temp->next = *a;
		(*a)->prev = temp;
		*a = temp;
	}
}