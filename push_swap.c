/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:47:57 by jesau             #+#    #+#             */
/*   Updated: 2026/07/21 20:47:24 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	push_swap(t_info *info)
{
//	int		i;
	float	disorder;

	disorder = compute_disorder(info->stack_a, info->size_a);
	if (check_dup(info->stack_a, info->size_a) == -1
		|| arr_sort_copy(info->stack_a, info->size_a) == -1)
		return (-1);
	if (disorder < 0.2)
		simple_algo(info);
	else if (disorder >= 0.2 && disorder < 0.5)
		medium_algo(info);
	else if (disorder >= 0.5)
		complex_algo(info);
/*	printf("%6s   %4s      %6s   %4s\n", "StackA", "Rank", "StackB", "Rank");
	i = 0;
	while (i < info->size_a)
	{
		printf("%6d   %4d", info->stack_a[i].nbr, info->stack_a[i].rank);
		if (i < info->size_b)
			printf("      %6d   %4d\n", info->stack_b[i].nbr,
				info->stack_b[i].rank);
		else
			printf("      %6s   %4s\n", "-", "-");
		i++;
	}
	printf("Simple = %b\nMedium = %b\nComplex = %b\nAdaptive = %b\nBench = %b\n",
		info->simple, info->medium, info->complex, info->adaptive, info->bench); */
	printf("Array disorder is %.2f\n", disorder);
	return (0);
}

float	compute_disorder(t_arr *stack, int size)
{
	int		i;
	int		j;
	float	mistakes;
	float	total_pairs;

	if (size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs += 1;
			if (stack[i].nbr > stack[j].nbr)
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}

int	check_min_max(char *str)
{
	int		i;
	long	nbr;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (-1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	nbr = ft_atol(str);
	if (nbr < -2147483648 || nbr > 2147483647)
		return (-1);
	return (0);
}
