/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:09:17 by cbossard          #+#    #+#             */
/*   Updated: 2015/02/12 11:09:18 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char**	exit_shell(int ac, char **av, char **env)
{
	free(av[ac]);
	av[ac] = 0;
	ft_freetab(av);
	ft_freetab(env);
	exit(0);
	return (0);
}

void	ft_sh1(char **env, t_cmd *cmd)
{
	char	*str;
	char	**av;

	while (1)
	{
		write(1, "$>", 2);
		str = ft_read();
		av = ft_strsplit(str, ' ');
		env = execute(av, env, cmd);
		ft_freetab(av);
		free(str);
	}
}

int		main(int ac, char **av, char **envp)
{
	char	**env;
	t_cmd	*cmd;
	
	if (!ac)
		ac = 0;
	if (!av)
		av = 0;
	env = i_env(envp);
	cmd = i_cmd();
	ft_sh1(env, cmd);
	return (0);
}
