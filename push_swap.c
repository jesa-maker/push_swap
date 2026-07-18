/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:47:57 by jesau             #+#    #+#             */
/*   Updated: 2026/07/18 13:52:33 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_arr *arr, int nbr_count)
{
	int		i;
	int		j;
	float	mistakes;
	float	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < nbr_count)
	{
		j = i + 1;
		while (j < nbr_count)
		{
			total_pairs += 1;
			if (arr[i].nbr > arr[j].nbr)
				mistakes += 1;
			j++;
		}
		i++;
	}
	printf("Disorder is %f%%\n", (mistakes / total_pairs) * 100);
	return (mistakes / total_pairs);
}

int	push_swap(char **argv, t_arr *arr, int nbr_count)
{
	int	i;
	int	j;

	(void)argv;
	i = 0;
	while (i < nbr_count)
	{
		j = i + 1;
		while (j < nbr_count)
		{
			if (arr[i].nbr == arr[j].nbr)
				return (1);
			j++;
		}
		i++;
	}
	compute_disorder(arr, nbr_count);
	return (0);
}
