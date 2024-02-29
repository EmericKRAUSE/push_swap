/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:39:38 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/29 16:01:01 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

t_stack	*find_the_smallest(t_stack *stack)
{
	t_stack *smallest;
	
	if (!stack)
		return (NULL);
	smallest = stack;
	while (stack)
	{
		if (stack->content < smallest->content)
			smallest = stack;
		stack = stack->next;
	}
	return(smallest);
}

int	get_index(t_stack *smallest, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack && stack != smallest)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	is_all_indexed(t_stack *stack)
{
	while (stack)
	{
		if (stack->index < 0)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	init_index(t_stack **a)
{
	t_stack *temp;
	int	smallest;
	int	index;

	index = 0;
	while (!is_all_indexed(*a))
	{
		temp = *a;
		smallest = 2147483647;
		while (temp)
		{
			if (temp->index == -1 && temp->content < smallest)
				smallest = temp->content;
			temp = temp->next;
		}
		temp = *a;
		while (temp)
		{
			if (temp->content == smallest && temp->index == -1)
			{
				temp->index = index;
				index++;
			}
			temp = temp->next;
		}
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (count_stack(*a) > 3 && !stack_is_sorted(*a))
		pb(b, a);
}

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		init_with_split(&argv, &a);
	else if (argc > 2)
		init_without_split(&argv, &a);
	if (!is_sorted(a))
	{
		if (count_stack(a) == 2)
			sa(&a);
		else if (count_stack(a) == 3)
			sort_three(&a);
		else if (count_stack(a) > 3)
			sort_stack(&a, &b);
	}
	free_list(&a);
	free_list(&b);
	return (0);
}
