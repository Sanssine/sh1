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

char**	print_env(int ac, char **av, char **env)
{
	int		i;

	if (ac > 1)
	{
		write(2, "env: ", 4);
		ft_putstr_fd(av[0], 2);
		write(2, ": Permission denied\n", 20);
	}
	else
	{
		i = -1;
		while(env[++i])
		{
			ft_putstr(env[i]);
			write(1, "\n", 1);
		}
	}
	return (env);
}

void	add_env(char **env, char *add)
{
	if (add && env)
	{
		while (*env)
			++env;
		*env = ft_memalloc(ft_strlen(add) + 1);
		ft_strcpy(*env, add);
	}
}

int		test_arg(char *arg)
{
	char	*i;

	i = strchr(arg, '=');
	if (!i)
		return (0);
	while (--i != arg)
		if ((*i > 'Z' || *i < 'A') && *i != '_')
			return (0);
	if ((*i > 'Z' || *i < 'A') && *i != '_')
			return (0);
	return (1);
}

char	**arg_set(int ac, char **av)
{
	char	**setenv;
	int		i;

	i = 0;
	setenv = ft_taballoc(ac + 1);
	while (*av)
	{
		if (test_arg(*av))
		{
			setenv[i] = *av;
			i++;
		}
		av++;
	}
	return (setenv);
}

char	**ft_setenv(int ac, char **av, char **env)
{
	char	**setenv;
	char	**new_env;
	int		i;

	setenv = arg_set(ac - 1, av + 1);
	print_tab(setenv);
	new_env = ft_taballoc(size_tab(env) + size_tab(setenv) + 1);
	i = -1;
	while (env[++i])
		add_env(new_env, env[i]);
	i = -1;
	while (setenv[++i])
		add_env(new_env, setenv[i]);
	ft_freetab(env);
	free(setenv);
	return (new_env);
}