/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:10:18 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/10 16:10:18 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int n;

	n = 0;
	if (!str)
		return (0);
	while (str[n] != 0)
		n++;
	return (n);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (ft_strlen((char*)s1) + ft_strlen(\
		(char*)s2)) + 1);
	if (!s1 || !s2)
		return (0);
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = 0;
	return (str);
}
