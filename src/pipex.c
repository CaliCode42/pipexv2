/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:50:41 by tcali             #+#    #+#             */
/*   Updated: 2025/04/23 14:39:37 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(char *command, char **env)
{
	char	**args;
	char	*path;

	if (ft_strchr(command, ';') || ft_strchr(command, '&')
		|| ft_strchr(command, '|') || ft_strchr(command, '*'))
	{
		args = malloc(sizeof(char *) * 4);
		if (!args)
			error_exit("malloc failed", 1);
		args[0] = ft_strdup("/bin/sh");
		args[1] = ft_strdup("-c");
		args[2] = ft_strdup(command);
		args[3] = NULL;
		path = ft_strdup("/bin/sh");
	}
	else
	{
		args = ft_split(command, ' ');
		if (!args || !args[0])
			error_exit("invalid command", 1);
		path = get_command_path(args[0], env);
		if (!path)
		{
			ft_printf_fd(2, "%s : command not found\n", args[0]);
			free_array(args);
			exit(127);
		}
	}
	if (execve(path, args, env) == -1)
	{
		if (path != args[0])
			free(path);
		free_array(args);
		error_exit("error executing command", 1);
	}
}

void	child1(int pipe_fd[2], t_pipex_data *data)
{
	int	fd;

	fd = open(data->file1, O_RDONLY, 0644);
	if (fd < 0)
		error_exit("no such file or directory", 1);
	dup2(pipe_fd[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(fd);
	execute_command(data->cmd1, data->envp);
}

void	child2(int pipe_fd[2], t_pipex_data *data)
{
	int	fd;

	fd = open(data->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		error_exit("permission denied", 1);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	close(fd);
	execute_command(data->cmd2, data->envp);
}

void	parent(int pipe_fd[2], t_pipex_data *data)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(data->pid1, NULL, 0);
	waitpid(data->pid2, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex_data	data;

	if (ac != 5)
		error_exit("usage: ./pipex file1 cmd1 cmd2 file2", 1);
	init_pipex_data(&data, av, envp);
	if (pipe(data.pipe_fd) < 0)
		error_exit("failed to create pipe", 1);
	data.pid1 = fork();
	if (data.pid1 < 0)
		error_exit("failed to fork first process", 1);
	if (data.pid1 == 0)
		child1(data.pipe_fd, &data);
	data.pid2 = fork();
	if (data.pid2 < 0)
		error_exit("failed to fork second process", 1);
	if (data.pid2 == 0)
		child2(data.pipe_fd, &data);
	parent(data.pipe_fd, &data);
	return (0);
}
