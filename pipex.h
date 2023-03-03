/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:59:35 by yli               #+#    #+#             */
/*   Updated: 2023/01/26 20:05:37 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
// for write, read, close, access, pipe, dup2, execve, fork
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
//for malloc, free, exit
# include <stdlib.h>
//for open, unlink
# include <fcntl.h>
//for waitpid, wait
# include <sys/wait.h>
//for perror
# include <stdio.h>
# include <stddef.h>
# include "./libft/libft.h"

char	*ft_strjoin_path_cmd(char const *s1, char c, char const *s2);
char	**split_path(char **envp);
void	check_free_all(char **str);
void	ft_executer(char *cmd, char **envp);
void	first_command_executer(int *fd, char **argv, char **envp);
void	second_command_executer(int *fd, char **argv, char **envp);
void	pipex(int argc, char **argv, char **envp);
int		ft_perror(char *str);
char	**ft_check_cmd(char *cmd);

#endif
