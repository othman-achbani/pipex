/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:20:42 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/11 13:06:32 by oachbani         ###   ########.fr       */
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

void	ft_checknull(char **av)
{
	if (!*av[2] && !*av[3])
	{
		ft_putstr_fd("command not found : \n", 2);
		ft_putstr_fd("command not found : ", 2);
		exit(1);
	}
	if (!*av[2])
	{
		ft_putstr_fd("command not found : \n", 2);
		exit(1);
	}
	if (!*av[3])
	{
		ft_putstr_fd("command not found : \n", 2);
		exit(1);
	}
	if (!check_spaces(2, ++av))
	{
		ft_putstr_fd("command not found : \n", 2);
		exit(1);
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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
