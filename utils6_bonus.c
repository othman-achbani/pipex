/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:23:26 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/18 18:52:24 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	cold_arms(char *line, char *limiter)
{
	char	*join;

	join = ft_strjoin(limiter, "\n");
	if (ft_strncmp(join, \
			line, ft_strlen(limiter) + 1) == 0)
	{
		free(line);
		free(join);
		exit(EXIT_FAILURE);
	}
	free(join);
}

void	for_norm(int infd, char *file1, int *i)
{
	*i = 2;
	infd = get_fd(file1, 0);
	dup2(infd, 0);
}
