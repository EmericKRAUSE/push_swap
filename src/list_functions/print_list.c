/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:10:26 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/29 15:25:46 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	print_list(t_stack *stack)
{
	int	i;

	i = 0;
	printf("print:\n");
	while (stack)
	{
		printf("%d: %d\n", i++, stack->content);
		stack = stack->next;
	}
	printf("\n");
}
