/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:38:05 by jesau             #+#    #+#             */
/*   Updated: 2026/07/07 21:44:01 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dig_count(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	if (n > 0)
		n = -n;
	while (n < 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		size;
	int		neg_flag;
	char	*string;

	neg_flag = (n < 0);
	size = dig_count(n);
	if (n >= 0)
		n = -n;
	string = (char *)malloc(sizeof(char) * (size + 1));
	if (!string)
		return (NULL);
	string[size] = '\0';
	if (neg_flag == 1)
		string[0] = '-';
	while (size > neg_flag)
	{
		size--;
		string[size] = -(n % 10) + '0';
		n = n / 10;
	}
	return (string);
}
/*
int	main(void)
{
	int		nbr = 0;
	char	*ptr;

	ptr = ft_itoa(nbr);
	if (ptr)
	{
		printf("%s\n", ptr);
		free(ptr); // <--- Add this line to free the memory allocated by malloc
	}
	return (0);
} */
