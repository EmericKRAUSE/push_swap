/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:56:52 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/21 11:16:30 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	handle_error(t_stack **a, char ***numbers)
{
	free_list(a);
    if (numbers && *numbers)
        free_tab(numbers);
    ft_error();
}
