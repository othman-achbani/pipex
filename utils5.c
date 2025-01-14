/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:03:28 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/14 11:49:34 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_writefreecmd(char *str, char **spl, char *exe)
{
	ft_putstr_fd(str, 2);
	ft_free(spl);
	free(exe);
	exit(127);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
