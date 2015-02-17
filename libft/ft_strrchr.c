/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:16:41 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/04 16:16:41 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char			*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen((char*)s);
	while (i >= 0)
	{
		if ((char)c == s[i])
			return ((char*)s + i);
		i--;
	}
	return (0);
}
