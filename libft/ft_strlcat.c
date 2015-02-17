/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:11:52 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/04 15:11:52 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	ft_strlen(char *str)
{
	size_t n;

	n = 0;
	if (!str)
		return (0);
	while (str[n] != 0)
		n++;
	return (n);
}

size_t			ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dst);
	j = n - i - 1;
	if (!(n > i))
		return (n + ft_strlen((char*)src));
	k = 0;
	while (k < j)
	{
		dst[k + i] = src[k];
		k++;
	}
	dst[k + i] = 0;
	return (i + ft_strlen((char*)src));
}
