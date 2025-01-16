/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:20:42 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/16 12:36:31 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	ft_checknull(char *cmd)
{
	if (!cmd || !check_spaces(cmd))
		return(0);
	return(1);
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
