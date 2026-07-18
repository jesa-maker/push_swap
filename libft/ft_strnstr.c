/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:33:35 by jesau             #+#    #+#             */
/*   Updated: 2026/07/07 20:33:07 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (1)
		{
			if (i + j >= len || little[j] == '\0')
				break ;
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*haystack = "42School";
	char		*res;

	printf("--- Testing ft_strnstr ---\n");
	printf("Haystack: \"%s\"\n\n", haystack);

	// Test 1: Standard successful match
	res = ft_strnstr(haystack, "School", 8);
	printf("Test 1 (Standard Match 'School', len=8): \n");
	printf("Result: %s\n\n", res ? res : "NULL");

	// Test 2: Substring exists but is cut off by the len limit
	res = ft_strnstr(haystack, "School", 5);
	printf("Test 2 (Boundary Cap 'School', len=5): \n");
	printf("Result: %s (Expected: NULL)\n\n", res ? res : "NULL");

	// Test 3: Tricky edge case - Empty needle string
	res = ft_strnstr(haystack, "", 8);
	printf("Test 3 (Empty Needle \"\", len=8): \n");
	printf("Result: %s (Expected: 42School)\n\n", res ? res : "NULL");

	// Test 4: Needle character matches partially but breaks
	res = ft_strnstr(haystack, "Schol", 8);
	printf("Test 4 (Partial Match 'Schol', len=8): \n");
	printf("Result: %s (Expected: NULL)\n", res ? res : "NULL");

	return (0);
}*/
