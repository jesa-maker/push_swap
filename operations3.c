/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 13:03:59 by jesau             #+#    #+#             */
/*   Updated: 2026/07/20 13:13:26 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_info *info)
{
	int		i;
	t_arr	tmp;

	if (info->size_a >= 2)
	{
		tmp = info->stack_a[info->size_a - 1];
		i = info->size_a;
		while (--i > 0)
			info->stack_a[i] = info->stack_a[i - 1];
		info->stack_a[i] = tmp;
	}
	if (info->size_b >= 2)
	{
		tmp = info->stack_b[info->size_b - 1];
		i = info->size_b;
		while (--i > 0)
			info->stack_b[i] = info->stack_b[i - 1];
		info->stack_b[i] = tmp;
	}
	write(1, "rrr\n", 4);
}
