/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_print_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:09:41 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/21 14:09:51 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse_print_list(t_stack *stack)
{
	t_stack *last;
	int	i;

	last = ps_lstlast(stack);
	i = 0;
	printf("reverse print:\n");
	while (last != NULL)
	{
		printf("%d: %d\n", i++, last->content);
		last = last->prev;
	}
	printf("\n");
}
