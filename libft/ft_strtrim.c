/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:21:39 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/10 16:21:39 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_strlen(char *str)
{
	int n;

	n = 0;
	if (!str)
		return (0);
	while (str[n] != 0)
		n++;
	return (n);
}

char			*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	k = -1;
	if (!s)
		return (0);
	j = ft_strlen((char*)s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	if (j < i)
	{
		str = (char*)malloc(1);
		str[0] = 0;
		return (str);
	}
	str = (char*)malloc(sizeof(char) * (j - i) + 2);
	while (++k + i <= j)
		str[k] = ((char*)s)[k + i];
	str[k] = 0;
	return (str);
}
