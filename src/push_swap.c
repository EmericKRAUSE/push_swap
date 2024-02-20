/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:39:38 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/20 14:49:20 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(void)
{
	ft_putendl_fd("Error", 1);
	exit(EXIT_FAILURE);
}

t_stack	*ps_lstnew(char *content)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->content = ft_atoi(content);
	elem->next = NULL;
	return (elem);
}

t_stack	*ps_lstlast(t_stack *stack)
{
	t_stack	*temp;

	temp = NULL;
	if (stack != NULL)
	{
		temp = stack;
		while (temp-> next)
		{
			temp = temp->next;
		}
	}
	return (temp);
}


void	ps_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack != NULL && new != NULL)
	{
		if (*stack == NULL)
			*stack = new;
		else
		{
			last = ps_lstlast(*stack);
			last->next = new;
		}
	}
}

void	free_list(t_stack **stack)
{
	t_stack	*previous;

	while (*stack)
	{
		previous = *stack;
		*stack = (*stack)->next;
		free (previous);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i++]);
	}
	free(tab);
}

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

void	create_a_list(char **tab, t_stack **stack)
{
	t_stack			*node;
	int					i;
	
	i = 0;
	*stack = ps_lstnew(tab[i++]);
	while (tab[i])
	{
		node = ps_lstnew(tab[i]);
		ps_lstadd_back(stack, node);
		i++;
	}
}

void	print_list(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
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

void	init_with_split(char ***argv, t_stack **a)
{
	char	**numbers;
	numbers = ft_split((*argv)[1], ' ');
	if (!tab_is_digit(numbers))
	{
		free_tab(numbers);
		ft_error();
	}
	if (!is_int(numbers))
	{
		free_tab(numbers);
		ft_error();
	}
	create_a_list(numbers, a);
	print_list(*a);
	free_list(a);
	free_tab(numbers);
}

void	init_without_split(char ***argv, t_stack **a)
{
	if (!tab_is_digit(*argv + 1))
		ft_error();
	if (!is_int(*argv + 1))
		ft_error();
	create_a_list(*argv + 1, a);
	print_list(*a);
	free_list(a);
}

int	main(int argc, char **argv)
{
	t_stack			*a;
	//t_stack			*b;

	a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		init_with_split(&argv, &a);
	else if (argc > 2)
		init_without_split(&argv, &a);
}
