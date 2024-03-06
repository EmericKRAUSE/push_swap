/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_occurence.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:40:56 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/06 10:57:42 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static	int	search_in_stack(t_stack *stack, int nb)
{
	while (stack)
	{
		if (stack->content == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	check_for_occurrence(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		if (search_in_stack(current->next, current->content))
			return (1);
		current = current->next;
	}
	return (0);
}
