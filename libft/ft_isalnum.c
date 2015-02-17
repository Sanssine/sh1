/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:55:13 by cbossard          #+#    #+#             */
/*   Updated: 2014/11/06 16:55:14 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(int c)
{
	if (47 < c && c < 58)
		return (1);
	return (0);
}

static int	ft_isalpha(int c)
{
	if ((64 < c && 91 > c) || (96 < c && c < 123))
		return (1);
	return (0);
}

int			ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
