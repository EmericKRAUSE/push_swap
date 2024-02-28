/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:39:38 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/28 14:19:26 by ekrause          ###   ########.fr       */
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

void	init_with_split(char ***argv, t_stack **a)
{
	char	**numbers;
	
	numbers = ft_split((*argv)[1], ' ');
	if (!tab_is_digit(numbers) || !is_int(numbers))
		handle_error(a, &numbers);
	create_a_list(numbers, a);
	if (check_for_occurrence(*a))
		handle_error(a, &numbers);
	free_tab(&numbers);
}

void	init_without_split(char ***argv, t_stack **a)
{
	if (!tab_is_digit(*argv + 1) || !is_int(*argv + 1))
		ft_error();
	create_a_list(*argv + 1, a);
	if (check_for_occurrence(*a))
		handle_error(a, NULL);
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

void	sort_three(t_stack **stack)
{
	int	a;
	int b;
	int c;

	a = (*stack)->content;
	b = (*stack)->next->content;
	c = (*stack)->next->next->content;
	if (a > b && b > c)
	{
		swap(stack);
		ft_putendl_fd("sa", 1);
		reverse_rotate(stack);
		ft_putendl_fd("rra", 1);
	}
	else if (a > b && b < c && a > c)
	{
		rotate(stack);
		ft_putendl_fd("ra", 1);
	}
	else if (a < b && a < c)
	{
		swap(stack);
		ft_putendl_fd("sa", 1);
		rotate(stack);
		ft_putendl_fd("ra", 1);
	}
	else if (a < b && b > c)
	{
		reverse_rotate(stack);
		ft_putendl_fd("rra", 1);
	}
	else if (a > b && b < c && a < c)
	{
		swap(stack);
		ft_putendl_fd("sa", 1);
	}
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

t_stack	*find_the_tallest(t_stack *stack)
{
	t_stack *tallest;
	
	if (!stack)
		return (NULL);
	tallest = stack;
	while (stack)
	{
		if (stack->content > tallest->content)
			tallest = stack;
		stack = stack->next;
	}
	return(tallest);
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

void	insert(t_stack **a, t_stack	**b, t_stack *node)
{
	while (node->prev != NULL)
	{
		if	(get_index(node, *a) <= count_stack(*a) / 2)
		{
			ft_putendl_fd("ra", 1);
			rotate(a);
		}
		else if (get_index(node, *a) > count_stack(*a) / 2)
		{
			ft_putendl_fd("rra", 1);
			reverse_rotate(a);
		}
	}
	ft_putendl_fd("pb", 1);
	push(b, a);
}

void	insertion_sort(t_stack **a, t_stack **b)
{
	t_stack *smallest;

	while (count_stack(*b) != 0)
	{
		smallest = find_the_smallest(*b);
		while (smallest->prev != NULL)
		{
			if (get_index(smallest, *b) <= count_stack(*b) / 2)
			{
				ft_putendl_fd("rb", 1);
				rotate(b);
			}
			else
			{
				ft_putendl_fd("rrb", 1);
				reverse_rotate(b);
			}
		}
		ft_putendl_fd("pa", 1);
		push(a, b);
	}
}

t_stack	*scan_stack(t_stack *a, int nb)
{
	t_stack *top;
	t_stack *bottom;
	int	i;
	int j;

	top = a;
	bottom = ps_lstlast(a);
	i = 0;
	j = 0;
	while (top)
	{
		if (top->index <= 20 * nb)
			break ;
		i++;
		top = top->next;
	}
	while (bottom)
	{
		if (bottom->index <= 20 * nb)
			break ;
		j++;
		bottom = bottom->prev;
	}
	if (i <= j)
		return (top);
	else
		return (bottom);
}

void	sort(t_stack **a, t_stack **b)
{
	int chunk;
	int nb;
	t_stack *to_push;
	int i = 0;

	chunk = count_stack(*a) / 20;
	nb = 1;
	while (chunk > 0)
	{
		while (i < 20 * nb)
		{
			to_push = scan_stack(*a, nb);
			insert(a, b, to_push);
			i++;
		}
		nb++;
		chunk--;
	}
	while (*a)
	{
		ft_putendl_fd("pb", 1);
		push(b, a);
	}
	insertion_sort(a, b);
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
	init_index(&a);
	if (!is_sorted(a))
	{
		if (count_stack(a) == 2)
			swap(&a);
		else if (count_stack(a) == 3)
			sort_three(&a);
		else if (count_stack(a) > 3)
			sort(&a, &b);
	}
	free_list(&a);
	free_list(&b);
	return (0);
}
