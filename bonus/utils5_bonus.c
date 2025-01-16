/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:03:28 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/16 22:23:55 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_writefreecmd(char *str, char **spl)
{
	ft_putstr_fd(str, 2);
	ft_free(spl);
	exit(127);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	error(int i)
{
	ft_putstr_fd("Error ", 2);
	exit(i);
}

int	get_fd(char *av, int i)
{
	int	file;

	if (i == 0)
		file = open(av, O_RDONLY);
	else if (i == 1)
		file = open(av, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (file == -1)
		error(1);
	return (file);
}

int	ft_here_doc(char *limiter)
{
	int		pipefd[2];
	char	*line;
	pid_t	pid;

	line = get_next_line(0);
	if (pipe(pipefd) == -1)
		error(1);
	pid = fork();
	if (pid == -1)
		error(1);
	if (pid == 0)
	{
		close(pipefd[0]);
		while (line)
		{
			if (ft_strncmp(ft_strjoin(limiter, "\n"), \
			line, ft_strlen(limiter) + 1) == 0)
				return (free(line), exit(EXIT_SUCCESS), 0);
			write(pipefd[1], line, ft_strlen(line));
			line = get_next_line(0);
		}
		free(line);
	}
	close(pipefd[1]);
	return (dup2(pipefd[0], 0), wait(NULL));
}
