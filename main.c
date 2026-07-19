/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:19:26 by jesau             #+#    #+#             */
/*   Updated: 2026/07/19 21:55:28 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_flag(char *str)
{
	if (ft_strncmp("--simple", str, 10) == 0
		|| ft_strncmp("--medium", str, 10) == 0
		|| ft_strncmp("--complex", str, 10) == 0
		|| ft_strncmp("--adaptive", str, 10) == 0
		|| ft_strncmp("--bench", str, 10) == 0)
		return (1);
	return (0);
}

int	check_min_max(char *str)
{
	int		i;
	long	nbr;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	nbr = ft_atoi(str);
	if (nbr < -2147483648 || nbr > 2147483647)
		return (1);
	return (0);
}

int	init_push_swap_info(t_info *info, int argc, char **argv, int nbr_count)
{
	int	i;
	int	j;

	info->stack_a = malloc(sizeof(t_arr) * nbr_count);
	info->stack_b = malloc(sizeof(t_arr) * nbr_count);
	if (!info->stack_a || !info->stack_b)
	{
		free(info->stack_a);
		free(info->stack_b);
		return (1);
	}
	info->size_a = nbr_count;
	info->size_b = 0;
	j = 0;
	i = 1;
	while (i < argc)
	{
		if (!check_flag(argv[i]))
		{
			info->stack_a[j].nbr = (int)ft_atoi(argv[i]);
			info->stack_a[j].rank = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		nbr_count;
	t_info	info;

	i = 1;
	nbr_count = 0;
	while (i < argc)
	{
		if (!check_flag(argv[i]) && check_min_max(argv[i]))
		{
			ft_putendl_fd("Error", 1);
			return (0);
		}
		if (!check_flag(argv[i]))
			nbr_count++;
		i++;
	}
	if (init_push_swap_info(&info, argc, argv, nbr_count))
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	if (push_swap(argv, &info))
		ft_putendl_fd("Error", 1);
	free(info.stack_a);
	free(info.stack_b);
	return (0);
}
