/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:39:38 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/01 14:40:58 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next != NULL)
	{
		if (stack->content >= stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack *find_max(t_stack *stack)
{
	t_stack	*max;
	int best_match_index;

	max = NULL;
	best_match_index = -2147483648;
	while (stack)
	{
		if (stack->content > best_match_index)
		{
			best_match_index = stack->content;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}

t_stack *find_min(t_stack *stack)
{
	t_stack	*min;
	int best_match_index;

	min = NULL;
	best_match_index = 2147483647;
	while (stack)
	{
		if (stack->content < best_match_index)
		{
			best_match_index = stack->content;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

void	set_cheapest_a(t_stack *stack)
{
	t_stack	*cheapest_node;
	int		cheapest_value;

	cheapest_value = 2147483647;
	if (!stack)
		return ;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	set_cost_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = count_stack(a);
	len_b = count_stack(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - (a->target->index);
		a = a->next;
	}
}

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

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack *current_b;
	t_stack *target_node;
	int		best_match_index;

	target_node = NULL;
	while (a)
	{
		best_match_index = -2147483648;
		current_b = b;
		while (current_b)
		{
			if (current_b->content < a->content && current_b->content > best_match_index)
			{
				best_match_index = current_b->content;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == -2147483648)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

void	set_index(t_stack *stack)
{
	int i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = count_stack(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		i++;
		stack = stack->next;
	}
}

void	init_node_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}

void	init_node_a(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	set_cost_a(a, b);
	set_cheapest_a(a);
}

t_stack *get_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (cheapest_node->prev && cheapest_node->target->prev)
	{
		ra(a, 1);
		rb(b, 1);
		ft_putendl_fd("rr", 1);
	}
	set_index(*a);
	set_index(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (cheapest_node->prev && cheapest_node->target->prev)
	{
		rra(a, 1);
		rrb(b, 1);
		ft_putendl_fd("rrr", 1);
	}
	set_index(*a);
	set_index(*b);
}

void	prep_to_push(t_stack **stack, t_stack *to_rotate, char stack_name)
{
	while (to_rotate->prev)
	{
		if (stack_name == 'a')
		{
			if (to_rotate->above_median)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (stack_name == 'b')
		{
			if (to_rotate->above_median)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack *cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median && !(cheapest_node->target->above_median)))
		reverse_rotate_both(a, b, cheapest_node);
	prep_to_push(a, cheapest_node, 'a');
	prep_to_push(b, cheapest_node->target, 'b');
	pb(b, a);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_to_push(a, (*b)->target, 'a');
	pa(a, b);
}

void	min_on_top(t_stack **a)
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

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		init_with_split(&argv, &a);
	else if (argc > 2)
		init_without_split(&argv, &a);
	if (!is_sorted(a))
	{
		if (count_stack(a) == 2)
			sa(&a);
		else if (count_stack(a) == 3)
			sort_three(&a);
		else if (count_stack(a) > 3)
			sort_stack(&a, &b);
	}
	free_list(&a);
	free_list(&b);
	return (0);
}
