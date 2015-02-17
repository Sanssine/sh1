/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:10:51 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/04 16:10:52 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char		*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (i < ft_strlen((char*)s) + 1)
	{
		if ((char)c == s[i])
			return ((char*)s + i);
		i++;
	}
	return (0);
}
