/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:39:38 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/29 15:34:37 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	tab_is_digit(char **tab)
{
	int	y;
	int	x;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (ft_isdigit(tab[y][x]) || tab[y][x] == '-' || tab[y][x] == '+')
				x++;
			else
				return (0);
		}
		y++;
	}
	return (1);
}

int	is_int(char **tab)
{
	int			sign;
	long int	result;
	int			i;
	int			x;

	i = 0;
	while (tab[i])
	{
		result = 0;
		sign = 1;
		x = 0;
		if (tab[i][x] == '-' || tab[i][x] == '+')
		{
			if (tab[i][x] == '-')
				sign = -1;
			x++;
		}
		while (tab[i][x] >= '0' && tab[i][x] <= '9')
		{
			result = result * 10 + tab[i][x] - 48;
			x++;
		}
		result *= sign;
		if (result > 2147483647 || result < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	search_in_stack(t_stack *stack, int nb)
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
	while(current)
	{
		if (search_in_stack(current->next, current->content))
			return (1);
		current = current->next;
	}
	return (0);
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
	}
	free_list(&a);
	free_list(&b);
	return (0);
}
