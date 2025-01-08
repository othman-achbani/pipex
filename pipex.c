/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:32:30 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/08 21:53:53 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	child_cmd1(char *av, char **env)
// {
// 	int fd;
// 	char **str;

// 	str = ft_split(av)
// 	fd = open("test.txt", O_CREAT | O_RDWR , 0644);
		
// }

int main (int ac , char **av, char **env)
{
	int		pipefd[2];
	char	*PATH;
	char buffer[250] ={0};

	// if (ac != 5)
	// 	return(write(1, "syntax erreur try : file1 cmd1 cmd2 file2 \n", 44), 1);
	int i =pipe(pipefd);
	if (i == -1)
	{
		perror("error while opening the pipe");
		exit(1);
	}
	pid_t pid = fork();
	if (pid == 0)
	{
		// close(pipefd[1]);
		
		if (dup2(pipefd[1], 1) == -1)
		{
			perror ("error redirecting the fd");
			exit(EXIT_FAILURE);
		}
		close(pipefd[1]);
	 	char *ls_args[] = { "ls", NULL };
	 	execve("/bin/ls" ,ls_args, NULL);
	}
	else
	{
		wait(NULL);
		int fd = open("test.txt", O_CREAT | O_RDWR, 0644);
		if (dup2(pipefd[0], 0) == -1 || dup2(fd, 1) == -1)
		{
			perror("error redirecting the fd");
			exit(EXIT_FAILURE);
		}
		close(fd);
		close(pipefd[1]);
		char *ls_args[] = { "wc","-l", NULL };
		
		execve("/bin/wc" ,ls_args , NULL);
	}
}
