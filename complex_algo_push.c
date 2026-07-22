/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:23:57 by jesau             #+#    #+#             */
/*   Updated: 2026/07/22 11:19:33 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_bounds(t_info *info)
{
	if (info->total <= 100)
		info->frame = info->total / 5;
	else
		info->frame = info->total / 11;
	info->pivot = info->frame;
}

static void	quick_sort_push(t_info *info, int *i)
{
	pb(info);
	(*i)++;
	if (info->stack_b[0].rank < (info->pivot - (info->frame / 2)))
		rb(info);
	if (*i == info->frame)
	{
		info->pivot += info->frame;
		*i = 0;
	}
}

void	complex_algo(t_info *info)
{
	int	elements_pushed;

	elements_pushed = 0;
	init_bounds(info);
	while (info->size_a > 3)
	{
		if (info->stack_a[0].rank < info->pivot)
			quick_sort_push(info, &elements_pushed);
		else if (info->stack_a[info->size_a - 1].rank < info->pivot)
		{
			rra(info);
			quick_sort_push(info, &elements_pushed);
		}
		else
			ra(info);
	}
	sort_three(info);
	return_push(info);
}
