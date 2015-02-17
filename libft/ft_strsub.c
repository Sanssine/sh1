/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:41:39 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/10 15:41:39 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = (char*)malloc(sizeof(char) * len + 1);
	i = 0;
	if (!s || !*s || !len)
		return (0);
	while (i < len)
	{
		str[i] = s[(size_t)start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
