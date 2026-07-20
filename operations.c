/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 11:06:56 by jesau             #+#    #+#             */
/*   Updated: 2026/07/20 12:42:04 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info)
{
	t_arr	tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->stack_a[0];
	info->stack_a[0] = info->stack_a[1];
	info->stack_a[1] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_info *info)
{
	t_arr	tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->stack_b[0];
	info->stack_b[0] = info->stack_b[1];
	info->stack_b[1] = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_info *info)
{
	t_arr	tmp;

	if (info->size_a >= 2)
	{
		tmp = info->stack_a[0];
		info->stack_a[0] = info->stack_a[1];
		info->stack_a[1] = tmp;
	}
	if (info->size_b >= 2)
	{
		tmp = info->stack_b[0];
		info->stack_b[0] = info->stack_b[1];
		info->stack_b[1] = tmp;
	}
	write(1, "ss\n", 3);
}

void	pa(t_info *info)
{
	int	i;

	if (info->size_b <= 0)
		return ;
	i = info->size_a;
	while (i > 0)
	{
		info->stack_a[i] = info->stack_a[i - 1];
		i--;
	}
	info->stack_a[0] = info->stack_b[0];
	i = 0;
	while (i < info->size_b - 1)
	{
		info->stack_b[i] = info->stack_b[i + 1];
		i++;
	}
	info->size_a++;
	info->size_b--;
	write(1, "pa\n", 3);
}

void	pb(t_info *info)
{
	int	i;

	if (info->size_a <= 0)
		return ;
	i = info->size_b;
	while (i > 0)
	{
		info->stack_b[i] = info->stack_b[i - 1];
		i--;
	}
	info->stack_b[0] = info->stack_a[0];
	i = 0;
	while (i < info->size_a - 1)
	{
		info->stack_a[i] = info->stack_a[i + 1];
		i++;
	}
	info->size_a--;
	info->size_b++;
	write(1, "pb\n", 3);
}
