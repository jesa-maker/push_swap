/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 09:50:30 by jesau             #+#    #+#             */
/*   Updated: 2026/07/19 22:10:03 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

float	compute_disorder(t_arr *stack_a, int size_a)
{
	int		i;
	int		j;
	float	mistakes;
	float	total_pairs;

	if (size_a < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size_a)
	{
		j = i + 1;
		while (j < size_a)
		{
			total_pairs += 1;
			if (stack_a[i].nbr > stack_a[j].nbr)
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
