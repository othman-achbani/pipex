/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oachbani <oachbani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:38:08 by oachbani          #+#    #+#             */
/*   Updated: 2025/01/08 17:47:54 by oachbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdint.h>

void	ft_bzero(void *s, size_t len);
void	*ft_calloc(size_t num, size_t size);
void	*ft_memset(void *ptr, int value, size_t num);
char	**ft_split(char const *s, char c);
#endif