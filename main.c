/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:19:26 by jesau             #+#    #+#             */
/*   Updated: 2026/07/21 19:07:20 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	allocate_stacks(t_info *info)
{
	info->stack_a = malloc(sizeof(t_arr) * info->total);
	info->stack_b = malloc(sizeof(t_arr) * info->total);
	if (!info->stack_a || !info->stack_b)
	{
		free(info->stack_a);
		free(info->stack_b);
		return (-1);
	}
	info->size_a = info->total;
	info->size_b = 0;
	info->simple = false;
	info->medium = false;
	info->complex = false;
	info->adaptive = false;
	info->bench = false;
	return (0);
}

int	init_info(t_info *info, int argc, char **argv)
{
	int	i;
	int	j;

	if (allocate_stacks(info) == -1)
		return (-1);
	j = 0;
	i = 1;
	while (i < argc)
	{
		if (!check_flag(argv[i], info))
		{
			info->stack_a[j].nbr = ft_atol(argv[i]);
			info->stack_a[j].rank = 0;
			j++;
		}
		i++;
	}
	info->chunk_step = 20;
	if (info->total > 100)
		info->chunk_step = 45;
	info->chunk_size = info->chunk_step;
	return (0);
}

static int	count_validate(t_info *info, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!check_flag(argv[i], info) && (check_min_max(argv[i]) == -1))
			return (-1);
		if (!check_flag(argv[i], info))
			info->total++;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	info.total = 0;
	if (count_validate(&info, argc, argv) == -1)
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	if (init_info(&info, argc, argv) == -1)
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	if (push_swap(&info) == -1)
		ft_putendl_fd("Error", 1);
	free(info.stack_a);
	free(info.stack_b);
	return (0);
}
