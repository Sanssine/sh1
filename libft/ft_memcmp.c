/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:44:36 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/04 14:44:36 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*i;
	unsigned char	*j;
	size_t			k;

	k = 0;
	i = (unsigned char*)s1;
	j = (unsigned char*)s2;
	while (k < n)
	{
		if (i[k] != j[k])
			return (i[k] - j[k]);
		k++;
	}
	return (0);
}
