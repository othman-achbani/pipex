/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:20:42 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/18 16:45:45 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strdup(char *s)
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

size_t	ft_strlen(char *s)
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
		return (0);
	return (1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

t_pipex	fill_the_struct(int ac, int *in_ou_f, char **env)
{
	t_pipex	strct;

	strct.ac = ac;
	strct.env = env;
	strct.inf = in_ou_f[0];
	strct.outf = in_ou_f[1];
	return (strct);
}
