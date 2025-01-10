/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:34:23 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/10 23:28:48 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_checkfirst(char *str, char *path)
{
	char	**parse;
	parse = ft_split(path , ':');

	if (!parse)
		return(NULL);
	while (*parse)
	{
		if(access(str, X_OK) == 0)
			return(str);
		parse++;
	}
	return (NULL);
}

void ft_writefree(char *str, char **spl ,char *path)
{
	ft_putstr_fd(str, 2);
		return(ft_free(spl), free(path), exit(1));
}

int	check_spaces(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (!av[i][j])
			return (0);
	}
	return (1);
}