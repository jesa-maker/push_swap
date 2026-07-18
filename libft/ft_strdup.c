/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:35:28 by jesau             #+#    #+#             */
/*   Updated: 2026/07/07 20:29:51 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dup_str;

	len = ft_strlen(s);
	dup_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup_str[i] = s[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str = "duplicat";
	char	*dup;

	dup = ft_strdup(str);
	printf("%s\n", dup);
}*/
