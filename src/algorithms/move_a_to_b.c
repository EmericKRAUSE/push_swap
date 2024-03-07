/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:30:40 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/07 14:51:36 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static	void	reverse_rotate_both(t_stack **a, \
t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rrr(a, b, 1);
	set_index(*a);
	set_index(*b);
}

static	void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (cheapest_node->prev && cheapest_node->target->prev)
		rr(a, b, 1);
	set_index(*a);
	set_index(*b);
}

static	t_stack	*get_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && \
	!(cheapest_node->target->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	prep_to_push(a, cheapest_node, 'a');
	prep_to_push(b, cheapest_node->target, 'b');
	pb(b, a, 1);
}
