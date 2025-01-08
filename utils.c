/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:43:50 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/08 17:47:49 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	if (size && num > SIZE_MAX / size)
		return (NULL);
	p = malloc(num * size);
	if (!p)
		return (NULL);
	ft_bzero(p, num * size);
	return (p);
}

void	ft_bzero(void *s, size_t len)
{
	ft_memset(s, '\0', len);
}


void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;
	size_t			i;

	p = ptr;
	i = 0;
	while (i < num)
	{
		p[i] = value;
		i++;
	}
	return (p);
}
