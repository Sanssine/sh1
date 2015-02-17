/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:13:49 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/04 17:13:50 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t i;
	size_t j;

	j = 0;
	if (!to_find[0])
		return ((char*)str);
	while (*str != '\0' && j < n)
	{
		if (*str == *to_find)
		{
			i = 0;
			while (str[i] == to_find[i] && j + i < n)
			{
				i++;
				if (to_find[i] == '\0')
					return ((char*)str);
			}
		}
		str++;
		j++;
	}
	return ('\0');
}
