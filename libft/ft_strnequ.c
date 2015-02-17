/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:33:12 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/10 15:33:12 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1 && !s2)
		return (1);
	if (!(s1 && s2))
		return (0);
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		if (!s1[i] && !s2[i])
			return (1);
		i++;
	}
	return (1);
}
