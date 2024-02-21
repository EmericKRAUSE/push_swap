/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:12:29 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/21 13:12:37 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*ps_lstlast(t_stack *stack)
{
	t_stack	*temp;

	temp = NULL;
	if (stack != NULL)
	{
		temp = stack;
		while (temp-> next)
		{
			temp = temp->next;
		}
	}
	return (temp);
}