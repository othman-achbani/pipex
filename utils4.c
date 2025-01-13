/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:34:23 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/13 18:00:59 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_checkfirst(char *str)
{
	if (access(str, X_OK) == 0)
		return (str);
	return (NULL);
}

void	ft_writefree(char *str, char **spl, char *exe)
{
	ft_putstr_fd(str, 2);
	ft_free(spl);
	free(exe);
	exit(1);
}

int	check_spaces(char *av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i] == ' ')
		i++;
	if (!av[i])
		return (0);
	return (1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*p;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	i = ft_strlen(s1) + ft_strlen(s2);
	p = ft_calloc(i + 1, sizeof(char));
	if (!p)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		p[i] = s1[i];
	while (s2[++j])
		p[i++] = s2[j];
	return (p);
}
// void	error_handler(int pid, int spid, char *cmd, char *cmd2)
// {
	// 
// }
