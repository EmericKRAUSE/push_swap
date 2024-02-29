/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_a_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:11:07 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/29 15:16:38 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	create_list(char **tab, t_stack **stack)
{
	t_stack			*node;
	int					i;
	
	i = 0;
	while (tab[i])
	{
		node = ps_lstnew(tab[i]);
		ps_lstadd_back(stack, node);
		i++;
	}
}

