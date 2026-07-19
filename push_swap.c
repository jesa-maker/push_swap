/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:47:57 by jesau             #+#    #+#             */
/*   Updated: 2026/07/19 21:59:49 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	push_swap(char **argv, t_info *info)
{
	int		i;
	float	disorder;

	(void)argv;
	disorder = 0;
	if (check_dup(info->stack_a, info->size_a) 
		|| arr_sort_copy(info->stack_a, info->size_a))
		return (1);
	printf("%6s   %4s      %6s   %4s\n", "StackA", "Rank", "StackB", "Rank");
	
	i = 0;
	while (i < info->size_a)
	{
		printf("%6d   %4d", info->stack_a[i].nbr, info->stack_a[i].rank);
		if (i < info->size_b)
			printf("      %6d   %4d\n", info->stack_b[i].nbr, info->stack_b[i].rank);
		else
			printf("      %6s   %4s\n", "-", "-");
		i++;
	}
	disorder = compute_disorder(info->stack_a, info->size_a);
	printf("Array disorder is %.2f\n", disorder);
	
	return (0);
}
