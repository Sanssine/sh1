/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:52:54 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/03 13:52:55 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *d, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = d;
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
}
