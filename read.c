/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbossard <cbossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:09:17 by cbossard          #+#    #+#             */
/*   Updated: 2015/02/12 11:09:18 by cbossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	*ft_read(void)
{
	char	*cmd;
	char	*tur;
	char	buff[32];
	int		i;

	i = 31;
	cmd = (char*)malloc(sizeof(char) * 32);
	cmd[0] = 0;
	buff[31] = 0;
	while (i == 31)
	{
		i = read(0, buff, 31);
		buff[i] = 0;
		tur = cmd;
		cmd = ft_strjoin(cmd, buff);
		free(tur);
	}
	cmd[ft_strlen(cmd) - 1] = 0;
	return (cmd);
}
