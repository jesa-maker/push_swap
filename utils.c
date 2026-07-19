/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 09:50:30 by jesau             #+#    #+#             */
/*   Updated: 2026/07/19 22:59:38 by jesau            ###   ########.fr       */
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

int	check_dup(t_arr *stack_a, int size_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_a)
	{
		j = i + 1;
		while (j < size_a)
		{
			if (stack_a[i].nbr == stack_a[j].nbr)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	arr_ranker(t_arr *stack_a, int *sort_arr, int size_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_a)
	{
		j = 0;
		while (j < size_a)
		{
			if (stack_a[i].nbr == sort_arr[j])
			{
				stack_a[i].rank = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sort_arr);
}

int	arr_sort_copy(t_arr *stack_a, int size_a)
{
	int	i;
	int	j;
	int	key;
	int	*sort_arr;

	sort_arr = (int *)malloc(sizeof(int) * size_a);
	if (!sort_arr)
		return (1);
	i = 0;
	while (i < size_a)
	{
		key = stack_a[i].nbr;
		j = i - 1;
		while (j >= 0 && sort_arr[j] > key)
		{
			sort_arr[j + 1] = sort_arr[j];
			j--;
		}
		sort_arr[j + 1] = key;
		i++;
	}
	arr_ranker(stack_a, sort_arr, size_a);
	return (0);
}
