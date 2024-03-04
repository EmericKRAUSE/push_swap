/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:20:04 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/04 09:22:39 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack *current_a;
	t_stack *target_node;
	int		best_match_index;

	target_node = NULL;
	while (b)
	{
		best_match_index = 2147483647;
		current_a = a;
		while (current_a)
		{
			if (current_a->content > b->content && current_a->content < best_match_index)
			{
				best_match_index = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == 2147483647)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	init_node_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}