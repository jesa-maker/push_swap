/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:37:12 by jesau             #+#    #+#             */
/*   Updated: 2026/07/06 13:08:57 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_set(int *set_arr, char const *set)
{
	int	i;

	i = -1;
	while (i++ < 255)
		set_arr[i] = 0;
	i = -1;
	while (set[++i])
		set_arr[(unsigned char)set[i]] = 1;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		set_arr[256];
	int		start;
	int		end;
	char	*new_s1;
	int		i;

	if (!s1 || !set)
		return (NULL);
	init_set(set_arr, set);
	start = 0;
	while (s1[start] && set_arr[(unsigned char)s1[start]] == 1)
		start++;
	end = ft_strlen(s1);
	while (end > start && set_arr[(unsigned char)s1[end - 1]] == 1)
		end--;
	new_s1 = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!new_s1)
		return (NULL);
	i = 0;
	while (start < end)
		new_s1[i++] = s1[start++];
	new_s1[i] = '\0';
	return (new_s1);
}
/*
#include <stdio.h>

int	main(void)
{
	char const	*set = "acbda";
	char const	*s1 = "abcHello world!cba";
	char		*result;

	result = ft_strtrim(s1, set);
	if (result)
	{
		printf("%s\n", result);
		free(result);
	}
}*/
