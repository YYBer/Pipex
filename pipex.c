/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:27:17 by yli               #+#    #+#             */
/*   Updated: 2023/01/26 20:07:23 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	**ft_check_cmd(char *cmd)
{
	char	**command;

	if (cmd == 0)
		ft_perror("0");
	else if (cmd[0] == '\0')
		ft_perror("0");
	command = ft_split(cmd, ' ');
	if (command == 0)
		ft_perror("1");
	return (command);
}	

void	ft_executer(char *cmd, char **envp)
{
	char	**command;
	char	**path;
	char	*path_cmd;
	int		i;

	command = ft_check_cmd(cmd);
	path = split_path(envp);
	if (path[0] == NULL)
		ft_perror("2");
	i = 0;
	while (path[i])
	{
		path_cmd = ft_strjoin_path_cmd(path[i], '/', command[0]);
		if (access(path_cmd, F_OK) != -1)
		{
			if (execve(path_cmd, command, NULL) == -1)
				ft_perror("3");
		}
		free (path_cmd);
		i++;
	}
	check_free_all(command);
	check_free_all(path);
	ft_perror("4");
}

void	first_command_executer(int *fd, char **argv, char **envp)
{
	int	fd_in;

	if (access(argv[1], R_OK) == -1)
		ft_perror("5");
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		ft_perror("5");
	if (dup2(fd_in, STDIN_FILENO) == -1)
		ft_perror("5");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_perror("5");
	close(fd_in);
	close(fd[0]);
	close(fd[1]);
	ft_executer(argv[2], envp);
}

void	second_command_executer(int *fd, char **argv, char **envp)
{
	int	fd_out;

	if (access(argv[4], F_OK) == 0 && access(argv[4], W_OK) == -1)
		ft_perror("6");
	fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_out < 0)
		ft_perror("6");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_perror("6");
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		ft_perror("6");
	close(fd[1]);
	close(fd[0]);
	close(fd_out);
	ft_executer(argv[3], envp);
}

void	pipex(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc != 5)
		ft_perror("7");
	if (pipe(fd) == -1)
		ft_perror("8");
	pid1 = fork();
	if (pid1 == -1)
		ft_perror("9");
	if (pid1 == 0)
		first_command_executer(fd, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		ft_perror("10");
	if (pid2 == 0)
		second_command_executer(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
