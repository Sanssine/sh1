/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:09:17 by cbossard          #+#    #+#             */
/*   Updated: 2015/02/12 11:09:18 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**cp_tab(char **tab)
{
	char	**cp;
	int		i;

	i = 0;
	cp = ft_taballoc(size_tab(tab) + 1);
	while (*tab)
	{
		cp[i] = ft_memalloc(ft_strlen(*tab) + 1);
		ft_strcpy(cp[i], *tab);
		tab++;
		i++;
	}
	return (cp);
}

void	rm_env(char **env, char **rm)
{
	int		i;

	i = 0;
	while (*env != *rm)
		env++;
	free(*rm);
	while (env[++i])
		env[i - 1] = env[i];
	env[i - 1] = 0;
}

char	**arg_unset(int ac, char **av)
{
	char	**unset;
	int		i;

	unset = ft_taballoc(ac + 1);
	i = -1;
	while (++i < ac)
		unset[i] = ft_strjoin(av[i], "=");
	return (unset);
}

char	**ft_unsetenv(int ac, char **av, char **env)
{
	char	**unset;
	char	**new_env;
	int		i;
	int		j;

	if (ac == 1)
	{
		write(2, "unsetenv: no argument\n", 22);
		return (env);
	}
	unset = arg_unset(ac - 1, av + 1);
	i = -1;
	while (env[++i])
	{
		j = -1;
		while (unset[++j])
			if (!ft_strncmp(unset[j], env[i], ft_strlen(unset[j])))
			rm_env(env, env + i);
	}
	new_env = cp_tab(env);
	ft_freetab(unset);
	ft_freetab(env);
	return (new_env);
}
