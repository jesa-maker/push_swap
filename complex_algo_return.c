/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo_return.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:24:24 by jesau             #+#    #+#             */
/*   Updated: 2026/07/22 11:57:09 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_max_ranks(t_info *info, int *max_data, int *max_idx2, int i)
{
	if (info->stack_b[i].rank > max_data[0])
	{
		max_data[1] = max_data[0];
		*max_idx2 = max_data[2];
		max_data[0] = info->stack_b[i].rank;
		max_data[2] = i;
	}
	else if (info->stack_b[i].rank > max_data[1])
	{
		max_data[1] = info->stack_b[i].rank;
		*max_idx2 = i;
	}
}

static int	get_two_max(t_info *info, int *max_idx2)
{
	int	i;
	int	max_data[3];

	max_data[0] = info->stack_b[0].rank;
	max_data[1] = -1;
	max_data[2] = 0;
	*max_idx2 = -1;
	i = 1;
	while (i < info->size_b)
	{
		update_max_ranks(info, max_data, max_idx2, i);
		i++;
	}
	return (max_data[2]);
}

static void	pair_rotation(t_info *info, int target_idx)
{
	if (target_idx <= info->size_b / 2)
	{
		while (target_idx-- > 0)
			rb(info);
	}
	else
	{
		while (target_idx++ < info->size_b)
			rrb(info);
	}
}

static void	pair_swap(t_info *info, int *max_idx2)
{
	int	max_idx1;

	pair_rotation(info, *max_idx2);
	pa(info);
	max_idx1 = get_two_max(info, max_idx2);
	pair_rotation(info, max_idx1);
	pa(info);
	sa(info);
}

void	return_push(t_info *info)
{
	int	max_idx[2];
	int	move_cost[2];

	while (info->size_b > 0)
	{
		if (info->size_b == 1)
		{
			pa(info);
			break ;
		}
		max_idx[0] = get_two_max(info, &max_idx[1]);
		move_cost[0] = max_idx[0];
		if (max_idx[0] > info->size_b / 2)
			move_cost[0] = info->size_b - max_idx[0];
		move_cost[1] = max_idx[1];
		if (max_idx[1] > info->size_b / 2)
			move_cost[1] = info->size_b - max_idx[1];
		if (move_cost[1] < move_cost[0])
			pair_swap(info, &max_idx[1]);
		else
			(pair_rotation(info, max_idx[0]), pa(info));
	}
}