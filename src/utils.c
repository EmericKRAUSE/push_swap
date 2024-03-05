/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:08:22 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/05 11:51:49 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	prep_to_push(t_stack **stack, t_stack *to_rotate, char stack_name)
{
	while (*stack != to_rotate)
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
	long best_match_index;

	if (!stack)
		return (NULL);
	max = NULL;
	best_match_index = LONG_MIN;
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
	long best_match_index;

	if (!stack)
		return (NULL);
	min = NULL;
	best_match_index = LONG_MAX;
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

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}