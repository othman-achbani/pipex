/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:38:08 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/16 12:32:40 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdint.h>
# include <stddef.h>

void	ft_writefreecmd(char *str, char **spl);
void	ft_free(char **tab);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void	ft_bzero(void *s, size_t len);
void	*ft_calloc(size_t num, size_t size);
void	*ft_memset(void *ptr, int value, size_t num);
char	**ft_split(char const *s, char c);
char	*get_path(char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_checkfirst(char *str);
void	ft_writefree(char *str, char **spl);
int		check_spaces(char *av);
void	error_handler(int pid, int spid, char *cmd, char *cmd2);
int		ft_checknull(char *cmd);
int		get_fd(char *av, int i);
void	error(int i);
void	empty_or_space(char *str, char **spl);
#endif