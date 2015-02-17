/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:10:55 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/10 15:10:56 by cbossard         ###   ########.fr       */
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

char		*ft_strmap(const char *s, char (*f)(char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char*)malloc(sizeof(char) * ft_strlen((char*)s) + 1);
	if (!str || !s)
		return (0);
	while (s[i])
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
