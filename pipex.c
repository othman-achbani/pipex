/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:32:30 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/10 12:03:06 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_check(char *str, char *path)
{
	char	**parse;

	parse = ft_split(path , ':');

	if (!parse)
		return(NULL);
	while (*parse)
	{
		if(access(str, X_OK) == 0)
			return(ft_strjoin(*parse,str));
		parse++;
	}
	ft_free(parse);
	return (NULL);
}

void	child_cmd1(int *pipefd, char **av, char **env)
{
	char	**str;
	char	*path;
	char	*exe;
	int		infd;

	infd = open (av[1], O_RDONLY);
	if (infd == -1)
	{
		perror("no such file or directory");
		exit (0);
	}
	path = get_path(env);
	str = ft_split(av[2], ' ');
	exe = ft_check(str[0], path);
	if (!exe)
	{
		ft_putstr_fd("command not found \n",2);
		return(ft_free(str), free(path),exit(127));
	}
	if (dup2(pipefd[1] ,1) == -1 || dup2(infd, 0) == -1)
	{
		ft_putstr_fd("error while redirecting the file \n",2);
		return(ft_free(str), free(path),exit(127));
	}
	execve(exe, str, env);
	ft_putstr_fd("error executing the command" ,2);
	exit(1);
}

void	second_cmd(int *pipefd, char **av, char **env)
{
	char	**str;
	char	*path;
	char	*exe;
	int		oufd;

	close (pipefd[1]);
	wait(NULL);
	oufd = open("test.txt", O_CREAT | O_RDWR, 0644);
	if (oufd == -1)
	{
		ft_putstr_fd("input file not found \n",2);
		return(ft_free(str), free(path),exit(127));
	}
	path = get_path(env);
	str = ft_split(av[3], ' ');
	exe = ft_check(str[0], path);
	if (!exe)
	{
		ft_putstr_fd("command not found \n",2);
		return(ft_free(str), free(path),exit(127));
	}
	if (dup2(pipefd[1] ,1) == -1 || dup2(oufd, 0) == -1)
	{
		ft_putstr_fd("error while redirecting the file \n",2);
		exit(1);
	}
	execve(exe, str, env);
	ft_putstr_fd("error executing the file \n",2);
	exit(1);
}

int main (int ac , char **av, char **env)
{
	int		pipefd[2];
	char	*PATH;
	int		fd;

	// if (ac != 5)
	// 	return(write(2, "syntax erreur try : file1 cmd1 cmd2 file2 \n", 44), 1);
	if (pipe(pipefd))
	{
		perror("error while opening the pipe");
		exit(1);
	}
	ft_checknull(av);
	pid_t pid = fork();
	if (pid == 0)
		child_cmd1(pipefd ,av, env);
	else
		second_cmd(pipefd, av, env);
}
