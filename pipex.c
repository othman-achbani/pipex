/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:32:30 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/13 17:48:50 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_check(char *str, char *path)
{
	char	**parse;
	char	*s;
	int		i;

	i = 0 ;
	parse = ft_split(path, ':');
	if (!parse)
		return (NULL);
	str = ft_strjoin("/", str);
	while (parse[i])
	{
		s = ft_strjoin(parse[i], str);
		if (access(s, X_OK) == 0)
			return (s);
		free(s);
		i++;
	}
	ft_free(parse);
	return (free(str), NULL);
}

void	child_cmd1(int *pipefd, char **av, char **env)
{
	char	**str;
	char	*path;
	char	*exe;
	int		infd;

	close(pipefd[0]);
	infd = open(av[1], O_RDONLY);
	if (infd == -1)
	{
		ft_putstr_fd("no such file or directory \n", 2);
		exit(0);
	}
	path = get_path(env);
	str = ft_split(av[2], ' ');
	if (!ft_checkfirst(str[0]))
		exe = ft_check(str[0], path);
	else
		exe = ft_checkfirst(str[0]);
	if (!exe)
		ft_writefree("", str, exe);
	else if (dup2(pipefd[1], 1) == -1 || dup2(infd, 0) == -1)
		ft_writefree("error while redirecting the file \n", str, exe);
	execve(exe, str, env);
	ft_writefree("error executing the command", str, exe);
}

void	second_cmd(int *pipefd, char **av, char **env)
{
	char	**str;
	char	*path;
	char	*exe;
	int		oufd;

	close(pipefd[1]);
	oufd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (oufd == -1)
	{
		ft_putstr_fd("can't create output file \n", 2);
		exit(1);
	}
	path = get_path(env);
	str = ft_split(av[3], ' ');
	if (!ft_checkfirst(str[0]))
		exe = ft_check(str[0], path);
	else
		exe = ft_checkfirst(str[0]);
	if (!exe)
		ft_writefree("", str, exe);
	if (dup2(pipefd[1], 1) == -1 || dup2(pipefd[0], 0) == -1)
		ft_writefree("error while redirecting the file \n", str, exe);
	execve(exe, str, env);
	ft_writefree("error executing the command", str, exe);
}

int	main(int ac, char **av, char **env)
{
	int		pipefd[2];
	int		i;
	pid_t	pid;
	pid_t	spid;
	int		exit;

	if (ac != 5)
		return (write(2, "syntax erreur try : file1 \
cmd1 cmd2 file2 \n", 44), 1);
	i = pipe(pipefd);
	if (i == -1)
		ft_writefree("error while redirecting the file \n", av, "h");
	ft_checknull(av);
	pid = fork();
	if (pid == 0)
		child_cmd1(pipefd, av, env);
	spid = fork();
	if (spid == 0)
		second_cmd(pipefd, av, env);
	waitpid(pid, &i, 0);
	waitpid(spid, &exit, 0);
	printf("pid = %d || spid = %d", i , exit);
	// error_handler(pid, spid, av[2], av[3]);
}
