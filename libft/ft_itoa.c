/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:59:53 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/10 17:59:54 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_itoa(int n)
{
	char	*str;
	int		i;
	int		k;

	i = 1;
	k = 1;
	while (++k && ((n / i) >= 10 || (n / i) <= -10))
		i *= 10;
	str = (char*)malloc(sizeof(char) * k + 1 + (n < 0));
	k = (n < 0);
	if (n < 0)
		str[0] = '-';
	while (i)
	{
		if (n < 0)
			str[k] = -(n / i) + 48;
		else
			str[k] = (n / i) + 48;
		n = n - (n / i) * i;
		i /= 10;
		k++;
	}
	str[k] = 0;
	return (str);
}
