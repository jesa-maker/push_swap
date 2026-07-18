/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:19:26 by jesau             #+#    #+#             */
/*   Updated: 2026/07/18 07:49:52 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

t_arr	*push_swap_arr(int argc, char **argv, int count)
{
	int		i;
	int		j;
	t_arr	*arr;

	arr = malloc(sizeof(t_arr) * count);
	if (!arr)
		return (NULL);
	j = 0;
	i = 1;
	while (i < argc)
	{
		if (!check_flag(argv[i]))
		{
			arr[j].nbr = ft_atoi(argv[i]);
			printf("%d\n", arr[j].nbr);
			j++;
		}
		i++;
	}
	return (arr);
}

int	main(int argc, char **argv)
{
	int		i;
	int		nbr_count;
	t_arr	*arr;

	i = 1;
	nbr_count = 0;
	arr = NULL;
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
	arr = push_swap_arr(argc, argv, nbr_count);
	free(arr);
	return (0);
}
