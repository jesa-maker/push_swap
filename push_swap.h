/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:15:59 by jesau             #+#    #+#             */
/*   Updated: 2026/07/18 13:38:00 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct ps_arr
{
	int	nbr;
	int	index;
}	t_arr;

int		main(int argc, char **argv);
int		push_swap(char **argv, t_arr *arr, int nbr_count);
t_arr	*push_swap_arr(int argc, char **argv, int count);
int		check_min_max(char *str);
int		check_flag(char *str);

#endif