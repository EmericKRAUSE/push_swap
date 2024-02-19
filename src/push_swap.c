/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:39:38 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/19 15:40:11 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_list(t_list **head)
{
	t_list	*previous;

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

int	main(int argc, char **argv)
{
	char			**numbers;
	t_list			*head;
	t_list			*node;
	int				i;

	i = 0;
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		head = ft_lstnew(numbers[i]);
		while (numbers[i])
		{
			node = ft_lstnew(numbers[i]);
			ft_lstadd_back(&head, node);
			i++;
		}
		node = head;
		while (node)
		{
			printf("%s\n", (char *)node->content);
			node = node->next;
		}
		free_list(&head);
		free_tab(&numbers);
	}
}