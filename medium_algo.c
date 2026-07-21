/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 23:13:44 by jesau             #+#    #+#             */
/*   Updated: 2026/07/21 14:26:16 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_chunk(t_info *info, int *i)
{
	pb(info);
	(*i)++;
	if (info->stack_b[0].rank < (info->chunk_size - (info->chunk_step / 2)))
		rb(info);
	if (*i == info->chunk_step)
	{
		info->chunk_size += info->chunk_step;
		*i = 0;
	}
}

void	rotate_update(t_info *info, int *pos)
{
	if (*pos > (info->size_b / 2))
		rrb(info);
	else
		rb(info);
	*pos = get_next(info);
}

static void	check_chunk_rra(t_info *info, int *i)
{
	rra(info);
	check_chunk(info, i);
}

void	medium_algo(t_info *info)
{
	int	i;
	int	pos;

	i = 0;
	while (info->size_a > 3)
	{
		if (info->stack_a[0].rank < info->chunk_size)
			check_chunk(info, &i);
		else if (info->stack_a[info->size_a - 1].rank < info->chunk_size)
			check_chunk_rra(info, &i);
		else
			ra(info);
	}
	sort_three(info);
	while (info->size_b > 0)
	{
		pos = get_next(info);
		while (pos != 0)
			rotate_update(info, &pos);
		pa(info);
	}
}
