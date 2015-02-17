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
/* *************************a************************************************* */

#include "sh1.h"

char**		execute(char **av, char **env, t_cmd *cmd)
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
