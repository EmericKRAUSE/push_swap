/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:40:16 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/07 15:29:53 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <string.h>

char	**read_push_swap()
{
	int		readed;
	char	**result;
	char 	*temp;
	char	buf[2];

	readed = 1;
	temp = ft_strdup("");
	if (!temp)
		return(NULL);
	while (readed > 0)
	{
		readed = read(0, buf, 1);
		if (readed < 0)
		{
			free(temp);
			return (NULL);
		}
		if (readed > 0)
		{
			buf[1] = '\0';
			temp = ft_strjoin(temp, buf);
			if (!temp)
			{
				free(temp);
				return (NULL);
			}
		}
	}
	result = ft_split(temp, '\n');
	free(temp);
	return (result);
}

void	execute_instructions(char **tab, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (tab[i])
	{

		if (!ft_strncmp(tab[i], "rra", 3))
			rra(a, 0);
		else if (!ft_strncmp(tab[i], "rrb", 3))
			rrb(b, 0);
		else if (!ft_strncmp(tab[i], "rrr", 3))
			rrr(a, b, 0);
		else if (!ft_strncmp(tab[i], "pa", 2))
			pa(a, b, 0);
		else if (!ft_strncmp(tab[i], "pb", 2))
			pb(b, a, 0);
		else if (!ft_strncmp(tab[i], "ra", 2))
			ra(a, 0);
		else if (!ft_strncmp(tab[i], "rb", 2))
			rb(b, 0);
		else if (!ft_strncmp(tab[i], "rr", 2))
			rr(a, b, 0);
		else if (!ft_strncmp(tab[i], "sa", 2))
			sa(a, 0);
		else if (!ft_strncmp(tab[i], "sb", 2))
			sb(b, 0);
		else
			handle_error(a, NULL);
		i++;
	}
}

void	print_list(t_stack *a)
{
	while (a)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	char			**tab;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		init_with_split(&argv, &a);
	else if (argc > 2)
		init_without_split(&argv, &a);
	tab = read_push_swap();
	execute_instructions(tab, &a, &b);
	if (is_sorted(a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_list(&a);
	return (0);
}