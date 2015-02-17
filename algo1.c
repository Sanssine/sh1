/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:09:17 by cbossard          #+#    #+#             */
/*   Updated: 2015/02/12 11:09:18 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	ft_freetab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

char	**ft_taballoc(int size)
{
	char **news;

	news = (char**)malloc(sizeof(char*) * size);
	if (!news)
		return (0);
	while (--size >= 0)
		news[size] = 0;
	return (news);
}

int		size_tab(char **tab)
{
	int		i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	print_tab(char **tab)
{
	if (tab)
		while (*tab)
		{
			ft_putstr(*tab);
			ft_putchar('\n');
			tab++;
		}
}

char	*ft_tri_join(char *str, char *ptdr, char *mdr)
{
	char *join;
	char *ze;

	join = ft_strjoin(str, ptdr);
	ze = join;
	join = ft_strjoin(join, mdr);
	free(ze);
	return (join);
}
