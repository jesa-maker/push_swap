/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:19:26 by jesau             #+#    #+#             */
/*   Updated: 2026/07/20 13:18:28 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	allocate_stacks(t_info *info, int nbr_count)
{
	info->stack_a = malloc(sizeof(t_arr) * nbr_count);
	info->stack_b = malloc(sizeof(t_arr) * nbr_count);
	if (!info->stack_a || !info->stack_b)
	{
		free(info->stack_a);
		free(info->stack_b);
		return (-1);
	}
	info->size_a = nbr_count;
	info->size_b = 0;
	info->simple = false;
	info->medium = false;
	info->complex = false;
	info->adaptive = false;
	info->bench = false;
	return (0);
}

int	init_info(t_info *info, int argc, char **argv, int nbr_count)
{
	int	i;
	int	j;

	if (allocate_stacks(info, nbr_count) == -1)
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
	return (0);
}

static int	count_validate(t_info *info, int argc, char **argv, int *nbr_count)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!check_flag(argv[i], info) && (check_min_max(argv[i]) == -1))
			return (-1);
		if (!check_flag(argv[i], info))
			(*nbr_count)++;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		nbr_count;
	t_info	info;

	nbr_count = 0;
	if (count_validate(&info, argc, argv, &nbr_count) == -1)
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	if (init_info(&info, argc, argv, nbr_count) == -1)
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
