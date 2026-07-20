/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 10:13:22 by jesau             #+#    #+#             */
/*   Updated: 2026/07/20 21:32:10 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_info *info)
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

void	sort_three_b(t_info *info)
{
	int	a;
	int	b;
	int	c;

	a = info->stack_b[0].rank;
	b = info->stack_b[1].rank;
	c = info->stack_b[2].rank;

	if (a > b && b < c && a < c)
		rrb(info);
	else if (a < b && b < c && a < c)
	{
		sb(info);
		rrb(info);
	}
	else if (a > b && b < c && a > c)
	{
		rrb(info);
		sb(info);
	}
	else if (a < b && b > c && a > c)
		sb(info);
	else if (a < b && b > c && a < c)
		rb(info);
}

void	simple_algo(t_info *info)
{
	int	pos;
	int	max_rank;

	max_rank = info->size_a;
	while (info->size_a > 3)
	{
		if ((info->stack_a[0].rank) < (max_rank - 3))
			pb(info);
		else
			ra(info);
	}
	sort_three_a(info);
	while (info->size_b > 0)
	{
		if (info->size_b == 3)
		{
			sort_three_b(info);
			pa(info);
			pa(info);
			pa(info);
			return ;
		}
		pos = get_next(info);
		if (pos == 0)
			pa(info);
		else if (pos > (info->size_b / 2))
			rrb(info);
		else if (pos <= (info->size_b / 2))
			rb(info);
	}
}

int	get_next(t_info *info)
{
	int	i;
	int	max_rank;
	int	max_index;

	max_rank = info->stack_b[0].rank;
	max_index = 0;
	i = 1;
	while (i < info->size_b)
	{
		if (info->stack_b[i].rank > max_rank)
		{
			max_rank = info->stack_b[i].rank;
			max_index = i;
		}
		i++;
	}
	return (max_index);
}
