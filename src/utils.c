/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:08:22 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/04 09:32:45 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	prep_to_push(t_stack **stack, t_stack *to_rotate, char stack_name)
{
	while (to_rotate->prev)
	{
		if (stack_name == 'a')
		{
			if (to_rotate->above_median)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (stack_name == 'b')
		{
			if (to_rotate->above_median)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

t_stack *find_max(t_stack *stack)
{
	t_stack	*max;
	int best_match_index;

	max = NULL;
	best_match_index = -2147483648;
	while (stack)
	{
		if (stack->content > best_match_index)
		{
			best_match_index = stack->content;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}

t_stack *find_min(t_stack *stack)
{
	t_stack	*min;
	int best_match_index;

	min = NULL;
	best_match_index = 2147483647;
	while (stack)
	{
		if (stack->content < best_match_index)
		{
			best_match_index = stack->content;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next != NULL)
	{
		if (stack->content >= stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	count_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}