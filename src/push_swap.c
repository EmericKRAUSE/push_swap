/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:39:38 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/20 11:38:43 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(void)
{
	ft_putendl_fd("Error", 1);
	exit(EXIT_FAILURE);
}

t_ps_list	*ps_lstnew(char *content)
{
	t_ps_list	*elem;

	elem = malloc(sizeof(t_ps_list));
	if (!elem)
		return (NULL);
	elem->content = ft_atoi(content);
	elem->next = NULL;
	return (elem);
}

t_ps_list	*ps_lstlast(t_ps_list *lst)
{
	t_ps_list	*temp;

	temp = NULL;
	if (lst != NULL)
	{
		temp = lst;
		while (temp-> next)
		{
			temp = temp-> next;
		}
	}
	return (temp);
}


void	ps_lstadd_back(t_ps_list **lst, t_ps_list *new)
{
	t_ps_list	*last;

	if (lst != NULL && new != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last = ps_lstlast(*lst);
			last->next = new;
		}
	}
}

void	free_list(t_ps_list **head)
{
	t_ps_list	*previous;

	while (*head)
	{
		previous = *head;
		*head = (*head)->next;
		free (previous);
	}
}

void	free_tab(char ***tab)
{
	int	i;

	i = 0;
	while ((*tab)[i])
		free ((*tab)[i++]);
	free((*tab));
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
			if (!ft_isdigit(tab[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	create_a_list(char **numbers, t_ps_list **head)
{
	t_ps_list			*node;
	int					i;
	
	i = 0;
	*head = ps_lstnew(numbers[i++]);
	while (numbers[i])
	{
		node = ps_lstnew(numbers[i]);
		ps_lstadd_back(head, node);
		i++;
	}
}

void	print_list(t_ps_list *head)
{
	while (head)
	{
		printf("%d\n", head->content);
		head = head->next;
	}
}

int	is_int(char **numbers)
{
	int			sign;
	long int	result;
	int			i;
	int			x;

	i = 0;
	while (numbers[i])
	{
		result = 0;
		sign = 1;
		x = 0;
		if (numbers[i][x] == '-' || numbers[i][x] == '+')
		{
			if (numbers[i][x] == '-')
				sign = -1;
			x++;
		}
		while (numbers[i][x] >= '0' && numbers[i][x] <= '9')
		{
			result = result * 10 + numbers[i][x] - 48;
			x++;
		}
		result *= sign;
		if (result > 2147483647 || result < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char			**numbers;
	t_ps_list			*head;

	if (argc < 2)
		return 1;
	if (argc == 2)
	{
		head = NULL;
		numbers = ft_split(argv[1], ' ');
		if (!tab_is_digit(numbers))
		{
			free_tab(&numbers);
			ft_error();
		}
		if (!is_int(numbers))
		{
			free_tab(&numbers);
			ft_error();
		}
		create_a_list(numbers, &head);
		print_list(head);
		free_list(&head);
		free_tab(&numbers);
	}
}