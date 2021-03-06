/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:09:17 by cbossard          #+#    #+#             */
/*   Updated: 2015/02/12 11:09:18 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**execute(char **av, char **env, t_cmd *cmd)
{
	int		i;

	i = size_tab(av);
	while (cmd)
	{
		if (!ft_strcmp(av[0], cmd->name))
		{
			env = cmd->f(i, av, env);
			return (env);
		}
		cmd = cmd->next;
	}
	write(2, av[0], ft_strlen(av[0]));
	write(2, ": command not found\n", 20);
	return (env);
}

char	**ft_cmd(int ac, char **av, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid != 0)
	{
		waitpid(pid, &status, 0);
		return (env);
	}
	else
	{
		ft_execve(av[1], av + 1, env);
		exit(0);
	}
}

void	ft_execve(char *cmd, char **av, char **env)
{
	int		i;
	int		j;
	char	**path;
	char	*dir;

	i = 0;
	j = 0;
	while (strncmp("PATH=", env[j], 5))
		j++;
	path = ft_strsplit((env[j]) + 5, ':');
	while (path[i])
	{
		dir = ft_tri_join(path[i], "/", cmd);
		execve(dir, av, env);
		free(dir);
		i++;
	}
}
