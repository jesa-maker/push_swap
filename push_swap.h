/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:15:59 by jesau             #+#    #+#             */
/*   Updated: 2026/07/20 21:02:22 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct ps_arr
{
	int	nbr;
	int	rank;
}	t_arr;

typedef struct s_info
{
	t_arr	*stack_a;
	t_arr	*stack_b;
	int		size_a;
	int		size_b;
	bool	simple;
	bool	medium;
	bool	complex;
	bool	adaptive;
	bool	bench;
}	t_info;

/* Main program engine and parsers */
int		main(int argc, char **argv);
int		push_swap(t_info *info);
int		init_info(t_info *info, int argc, char **argv, int nbr_count);

/* Sorting analytics and helpers */
void	arr_ranker(t_arr *arr, int *sort_arr, int size);
int		arr_sort_copy(t_arr *arr, int nbr_count);
float	compute_disorder(t_arr *stack, int size);
int		check_dup(t_arr *arr, int nbr_count);
int		check_min_max(char *str);
int		check_flag(char *str, t_info *info);
void	sort_three_a(t_info *info);
void	sort_three_b(t_info *info);
void	simple_algo(t_info *info);
int		get_next(t_info *info);

/* Stack Operations */
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);

#endif
