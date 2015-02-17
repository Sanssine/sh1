/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:09:17 by cbossard          #+#    #+#             */
/*   Updated: 2015/02/12 11:09:18 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct			s_cmd
{
	struct s_cmd		*next;
	char				*name;
	char**				(*f)(int, char**, char**);

}						t_cmd;

char	*ft_read();
void	ft_freetab(char **tab);
t_cmd	*i_cmd();
char	**execute(char **av, char **env, t_cmd *cmd);
char	**i_env(char **envp);
char	**ft_taballoc(int size);
int		size_tab(char **tab);
void	print_tab(char **tab);

char	**exit_shell(int ac, char **av, char **env);
char	**print_env(int ac, char **av, char **env);
char	**ft_unsetenv(int ac, char **av, char **env);
char	**ft_setenv(int ac, char **av, char **env);

#endif 
