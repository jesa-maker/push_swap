/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:37:37 by jesau             #+#    #+#             */
/*   Updated: 2026/07/08 08:17:04 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	if (!s || s[0] == '\0')
		return (0);
	words = 0;
	if (s[0] != c)
		words++;
	i = 1;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

static int	word_len(char const *s, int start, char c)
{
	int	len;

	len = 0;
	while (s[start] != c && s[start] != '\0')
	{
		len++;
		start++;
	}
	return (len);
}

static void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	int				i;
	unsigned int	j;
	char			**str;

	str = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c)
		{
			str[i] = ft_substr(s, j, word_len(s, j, c));
			if (!str[i])
				return (free_split(str), NULL);
			j += word_len(s, j, c);
			i++;
		}
		else
			j++;
	}
	str[i] = NULL;
	return (str);
}
/*
#include <stdio.h>

// Helper function to free the allocated matrix
void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	run_test(char const *s, char c)
{
	char	**result;
	int		i;

	printf("Testing string: \"%s\" with delimiter: '%c'\n", s, c);
	result = ft_split(s, c);
	if (!result)
	{
		printf("Result is NULL (Allocation failed or protection triggered)\n\n");
		return ;
	}
	i = 0;
	while (result[i])
	{
		printf("  [%d]: %s\n", i, result[i]);
		i++;
	}
	if (i == 0)
		printf("  (Empty array)\n");
	printf("\n");
	free_split(result);
}

int	main(void)
{
	printf("--- STARTING FT_SPLIT TESTS ---\n\n");

	// Test 1: Standard sentence
	run_test("Hello standard world test", ' ');

	// Test 2: Multiple consecutive delimiters
	run_test("---hello---world---42---", '-');

	// Test 3: Only delimiters
	run_test("XXXXX", 'X');

	// Test 4: Empty string
	run_test("", 'c');

	// Test 5: No delimiters present
	run_test("nodependency", ' ');

	// Test 6: Null terminator as delimiter
	run_test("hello", '\0');

	return (0);
}*/
