/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:49:17 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/06 15:49:18 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isprint(int c)
{
	if (c < 127 && c > 31)
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (47 < c && c < 58)
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (!ft_isprint(*str) || *str == ' ')
	{
		if (*str == '\0' || *str == '\033')
			return (0);
		str++;
	}
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	if (str[0] == '-')
		result = -result;
	return (result);
}
