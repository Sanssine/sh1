/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:32:18 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/11 16:26:16 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	((char*)dst)[i] = 0;
	return ((void *)dst);
}

static int	count(const char *s, char c)
{
	int		count;

	count = 0;
	if (!s || !c)
		return (0);
	while (1)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
		if (!*s)
			return (count);
	}
}

char		**ft_strsplit(const char *s, char c)
{
	char	**str;
	int		i;
	int		k;
	int		co;

	co = count(s, c);
	str = (char**)malloc(sizeof(char*) * co + 1);
	str[co] = 0;
	i = 0;
	while (i < co)
	{
		while (*s == c)
			s++;
		k = 0;
		while (s[k] && s[k] != c)
			k++;
		str[i] = (char*)malloc(sizeof(char) * k + 1);
		str[i][k] = 0;
		ft_memcpy(str[i], s, k);
		s += k;
		i++;
	}
	return (str);
}
