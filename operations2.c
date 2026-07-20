/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:50:39 by jesau             #+#    #+#             */
/*   Updated: 2026/07/20 13:02:32 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info)
{
	int		i;
	t_arr	tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->stack_a[0];
	i = -1;
	while (++i < info->size_a - 1)
		info->stack_a[i] = info->stack_a[i + 1];
	info->stack_a[info->size_a - 1] = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_info *info)
{
	int		i;
	t_arr	tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->stack_b[0];
	i = -1;
	while (++i < info->size_b - 1)
		info->stack_b[i] = info->stack_b[i + 1];
	info->stack_b[info->size_b - 1] = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_info *info)
{
	int		i;
	t_arr	tmp;

	if (info->size_a >= 2)
	{
		tmp = info->stack_a[0];
		i = -1;
		while (++i < info->size_a - 1)
			info->stack_a[i] = info->stack_a[i + 1];
		info->stack_a[info->size_a - 1] = tmp;
	}
	if (info->size_b >= 2)
	{
		tmp = info->stack_b[0];
		i = -1;
		while (++i < info->size_b - 1)
			info->stack_b[i] = info->stack_b[i + 1];
		info->stack_b[info->size_b - 1] = tmp;
	}
	write(1, "rr\n", 3);
}

void	rra(t_info *info)
{
	int		i;
	t_arr	tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->stack_a[info->size_a - 1];
	i = info->size_a;
	while (--i > 0)
		info->stack_a[i] = info->stack_a[i - 1];
	info->stack_a[i] = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_info *info)
{
	int		i;
	t_arr	tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->stack_b[info->size_b - 1];
	i = info->size_b;
	while (--i > 0)
		info->stack_b[i] = info->stack_b[i - 1];
	info->stack_b[i] = tmp;
	write(1, "rrb\n", 4);
}
