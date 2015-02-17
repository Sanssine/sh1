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
# include <sys/types.h>
# include <signal.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct		s_cmd
{
	struct s_cmd	*next;
	char			*name;
	char			**(*f)(int, char**, char**);
}					t_cmd;

char				*ft_read();
void				ft_freetab(char **tab);
t_cmd				*i_cmd();
char				**execute(char **av, char **env, t_cmd *cmd);
char				**i_env(char **envp);
char				**ft_taballoc(int size);
int					size_tab(char **tab);
void				print_tab(char **tab);
void				ft_execve(char *cmd, char **av, char **env);
char				*ft_tri_join(char *str, char *ptdr, char *mdr);
void				ft_execve(char *cmd, char **av, char **env);
char				**exit_shell(int ac, char **av, char **env);
char				**ft_env(int ac, char **av, char **env);
char				**ft_unsetenv(int ac, char **av, char **env);
char				**ft_setenv(int ac, char **av, char **env);

#endif
