/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:32:30 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/16 12:37:46 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_check(char *str, char *path)
{
	char	**parse;
	char	*s;
	int		i;
	char	*nstr;

	i = 0 ;
	parse = ft_split(path, ':');
	if (!parse || str[0] == '/' || str[0] == '.' || !str[0])
	{
		ft_free(parse);
		return (NULL);
	}	
	nstr = ft_strjoin("/", str);
	while (parse[i])
	{
		s = ft_strjoin(parse[i], nstr);
		if (access(s, X_OK) == 0)
			return (s);
		free(s);
		i++;
	}
	ft_free(parse);
	return (free(nstr), NULL);
}

void	child_cmd1(char *av, char **env)
{
	char	**str;
	char	*path;
	char	*exe;

	path = get_path(env);
	str = ft_split(av, ' ');
	if (!ft_checknull(av))
		empty_or_space("command not found : ", str);
	if (!ft_checkfirst(str[0]))
		exe = ft_check(str[0], path);
	else
		exe = ft_checkfirst(str[0]);
	if (!exe)
		ft_writefree("command not found : ",str);
	execve(exe, str, env);
	ft_writefree("i can't execute this command :",str);
}

void	execute_cmd(char *str, char **env)
{
	int		pipefd[2];
	pid_t	i;

	if (pipe(pipefd) == -1)
		error(1);
	i = fork();
	if (i == -1)
		error(1);
	if (i == 0)
	{
		close(pipefd[0]);
		if (dup2(pipefd[1], 1) == -1)
			perror("dup2 just failed");
		child_cmd1(str, env);
	}
	else
	{
		close(pipefd[1]);
		if (dup2(pipefd[0], 0) == -1)
			perror("dup2 just failed");
		wait(NULL);
	}
}

int	main(int ac, char **av, char **env)
{
	int		inf_or_outf[2];
	int		i;

	if (ac >= 5)
	{
		if (ft_strncmp("here_doc", av[1], 8) == 0 )
		{
			i = 3;
			
			
		}
		else
		{
			i = 2;
			inf_or_outf[0] = get_fd(av[1] , 0);
			inf_or_outf[1] = get_fd(av[ac - 1], 1);
			dup2(inf_or_outf[0], 0);
		}
		while (i < ac - 2)
			execute_cmd(av[i++], env);
		dup2(inf_or_outf[1], 1);
			child_cmd1(av[ac - 2], env);
	}
	else
		return(ft_putstr_fd("syntax error try file1 cmd1 cmd2 ... cmdn file2", 2), 1);
}
