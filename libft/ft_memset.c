/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:06:48 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/03 11:06:51 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *d, int nbr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char*)d)[i] = nbr;
		i++;
	}
	return (d);
}
