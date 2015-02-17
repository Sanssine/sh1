/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:09:17 by cbossard          #+#    #+#             */
/*   Updated: 2015/02/12 11:09:18 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**i_env(char **envp)
{
	char	**first;
	int		i;

	i = size_tab(envp);
	first = ft_taballoc(i + 1);
	while (--i > -1)
	{
		first[i] = ft_memalloc(ft_strlen(envp[i]) + 1);
		ft_strcpy(first[i], envp[i]);
	}
	return (first);
}

t_cmd	*new_cmd(char *str, char** (*fonction)(int, char**, char**))
{
	t_cmd	*news;

	news = (t_cmd*)malloc(sizeof(t_cmd));
	news->next = 0;
	news->name = ft_memalloc(ft_strlen(str) + 1);
	ft_strcpy(news->name, str);
	news->f = fonction;
	return (news);
}

void	add_cmd(t_cmd *first, char *n, char** (*f)(int, char**, char**))
{
	t_cmd *tmp;

	tmp = first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_cmd(n, f);
}

t_cmd	*i_cmd()
{
	t_cmd	*first;

	first = new_cmd("env", &(print_env));
	add_cmd(first, "exit", &(exit_shell));
	add_cmd(first, "unsetenv", &(ft_unsetenv));
	add_cmd(first, "setenv", &(ft_setenv));
	return (first);
}
