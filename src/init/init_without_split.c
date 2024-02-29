/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_without_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:34:48 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/29 15:35:00 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	init_without_split(char ***argv, t_stack **a)
{
	if (!tab_is_digit(*argv + 1) || !is_int(*argv + 1))
		ft_error();
	create_list(*argv + 1, a);
	if (check_for_occurrence(*a))
		handle_error(a, NULL);
}