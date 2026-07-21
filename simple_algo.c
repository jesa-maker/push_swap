/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 10:13:22 by jesau             #+#    #+#             */
/*   Updated: 2026/07/21 18:49:46 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_info *info)
{
	int	a;
	int	b;
	int	c;

	a = info->stack_a[0].rank;
	b = info->stack_a[1].rank;
	c = info->stack_a[2].rank;

	if (a > b && b < c && a < c)
		sa(info);
	else if (a > b && b > c && a > c)
	{
		sa(info);
		rra(info);
	}
	else if (a > b && b < c && a > c)
		ra(info);
	else if (a < b && b > c && a > c)
		rra(info);
	else if (a < b && b > c && a < c)
	{
		sa(info);
		ra(info);
	}
}

void	simple_algo(t_info *info)
{
	int	pos;

	while (info->size_a > 3)
	{
		if ((info->stack_a[0].rank) < (info->total - 3))
			pb(info);
		else
			ra(info);
	}
	sort_three(info);
	while (info->size_b > 0)
	{
		pos = get_next(info);
		while (pos != 0)
		{
			if (pos > (info->size_b / 2))
				rrb(info);
			else
				rb(info);
			pos = get_next(info);
		}
		pa(info);
	}
}
