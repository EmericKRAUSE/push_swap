/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:00:30 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/21 11:00:52 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
