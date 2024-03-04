/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:17:40 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/04 10:51:35 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static	void	min_on_top(t_stack **a)
{
	t_stack *min_node;

	min_node = find_min(*a);
	while (min_node->prev)
	{
		if (min_node->above_median)
			ra(a, 0);
		else
			rra(a, 0);
	}
}

static	void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_to_push(a, (*b)->target, 'a');
	pa(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{

	if (count_stack(*a) > 3 && !is_sorted(*a))
		pb(b, a);
	if (count_stack(*a) > 3 && !is_sorted(*a))
		pb(b, a);
	while (count_stack(*a) > 3 && !is_sorted(*a))
	{
		init_node_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_node_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	min_on_top(a);
}