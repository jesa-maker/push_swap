/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesau <jesau@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:34:43 by jesau             #+#    #+#             */
/*   Updated: 2026/07/07 19:45:36 by jesau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	count;
	void	*ptr;

	if (nmemb != 0 && size > ((size_t) - 1) / nmemb)
		return (NULL);
	count = nmemb * size;
	ptr = malloc(count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count);
	return (ptr);
}
