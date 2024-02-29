/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_is_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:37:50 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/29 15:38:18 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	tab_is_digit(char **tab)
{
	int	y;
	int	x;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (ft_isdigit(tab[y][x]) || tab[y][x] == '-' || tab[y][x] == '+')
				x++;
			else
				return (0);
		}
		y++;
	}
	return (1);
}