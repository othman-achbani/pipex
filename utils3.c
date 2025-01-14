/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:20:42 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/14 11:48:42 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*p;

	i = ft_strlen(s);
	p = (char *)ft_calloc(i + 1, sizeof(char));
	if (!p)
		return (NULL);
	i = -1;
	while (s[++i])
		p[i] = s[i];
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_checknull(char **av, char *cmd, char *cmd2)
{
	if ((!*av[2] && !*av[3]) || (!check_spaces(av[2]) \
	&& !check_spaces(av[3])))
	{
		ft_putstr_fd("command not found : ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putchar_fd('\n', 2);
		ft_putstr_fd("command not found : ", 2);
		ft_putstr_fd(cmd2, 2);
		return (ft_putchar_fd('\n', 2), exit(127));
	}
	if (!av[2])
		return (ft_putstr_fd("command not found : ", 2), \
ft_putchar_fd('\n', 2), ft_putstr_fd(cmd, 2), exit(127));
	if (!av[3])
		return (ft_putstr_fd("command not found : ", 2), \
ft_putchar_fd('\n', 2), ft_putstr_fd(cmd2, 2), exit(127));
	if (!check_spaces(av[2]) || !check_spaces(av[3]))
	{
		ft_putstr_fd("command not found : \n", 2);
		exit(127);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		ft_putchar_fd(s[i], fd);
}
