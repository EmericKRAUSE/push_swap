/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_with_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:34:13 by ekrause           #+#    #+#             */
/*   Updated: 2024/03/06 10:50:16 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	init_with_split(char ***argv, t_stack **a)
{
	char	**numbers;

	numbers = ft_split((*argv)[1], ' ');
	if (!tab_is_digit(numbers) || !is_int(numbers))
		handle_error(a, &numbers);
	create_list(numbers, a);
	if (check_for_occurrence(*a))
		handle_error(a, &numbers);
	free_tab(&numbers);
}
