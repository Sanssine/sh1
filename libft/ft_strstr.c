/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:12:00 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/04 17:12:00 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	j = 0;
	if (!str || !to_find)
		return (0);
	if (!to_find[0])
		return ((char*)str);
	while (str[j] != '\0')
	{
		i = 0;
		while (str[j + i] == to_find[i])
		{
			i++;
			if (to_find[i] == 0)
				return ((char*)str + j);
		}
		j++;
	}
	return (0);
}
