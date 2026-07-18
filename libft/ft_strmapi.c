/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:38:28 by jesau             #+#    #+#             */
/*   Updated: 2026/07/06 15:12:34 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*new_s;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
/*
#include <stdio.h>

char	test_uppercase(unsigned int i, char c)
{
	(void)i; // Silences "unused parameter" warnings
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char const	*original = "hello 42 school!";
	char		*result;

	printf("--- Testing ft_strmapi ---\n");
	printf("Original string: %s\n", original);

	result = ft_strmapi(original, test_uppercase);

	if (!result)
	{
		printf("❌ ERROR: Memory allocation failed.\n");
		return (1);
	}

	printf("Mapped string:   %s\n", result);

	// 2. Simple verification check
	printf("\nChecking differences:\n");
	printf("Original address: %p\n", (void *)original);
	printf("New string address: %p\n", (void *)result);

	if (original != result)
		printf("\n✅ SUCCESS: Created a brand new modified string!\n");
	else
		printf("\n❌ FAILURE: You modified the string in-place instead 
				of allocating new memory.\n");

	free(result);
	return (0);
}*/
