/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:39:17 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/18 18:52:52 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
		if (str[i] == (char)c)
			return ((char *)&str[i]);
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_getstrjoin(char *s1, char *s2)
{
	size_t	i;
	char	*p;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(i + 1);
	if (!p)
		return (free(s1), NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		p[i] = s1[i];
	while (s2[++j])
		p[i++] = s2[j];
	p[i] = '\0';
	free(s1);
	return (p);
}
