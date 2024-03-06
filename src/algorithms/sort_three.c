/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:29:25 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/06 10:46:57 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static	t_stack	*find_biggest(t_stack *a)
{
	t_stack	*biggest;

	if (!a)
		return (NULL);
	biggest = a;
	while (a)
	{
		if (a->content > biggest->content)
			biggest = a;
		a = a->next;
	}
	return (biggest);
}

void	sort_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_biggest(*a);
	if (biggest == *a)
		ra(a, 0);
	else if ((*a)->next == biggest)
		rra(a, 0);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}
