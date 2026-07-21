/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 17:37:24 by jesau             #+#    #+#             */
/*   Updated: 2026/07/21 20:37:11 by jesau            ###   ########.fr       */
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

static void	quick_push(t_info *info, int *i)
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

static void	push_to_a(t_info *info)
{
	int	pos;

	while (info->size_b > 0)
	{
		pos = get_next(info);
		while (pos != 0)
			rotate_update(info, &pos);
		pa(info);
	}
}

void	complex_algo(t_info *info)
{
	int	i;

	i = 0;
	init_bounds(info);
	while (info->size_a > 3)
	{
		if (info->stack_a[0].rank < info->pivot)
			quick_push(info, &i);
		else if (info->stack_a[info->size_a - 1].rank < info->pivot)
		{
			rra(info);
			quick_push(info, &i);
		}
		else
			ra(info);
	}
	sort_three(info);
	push_to_a(info);
}
