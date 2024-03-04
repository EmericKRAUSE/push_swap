/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:27:38 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/04 09:45:45 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
