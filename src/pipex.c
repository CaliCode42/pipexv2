/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:50:41 by tcali             #+#    #+#             */
/*   Updated: 2025/04/12 19:17:39 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(const char *msg, int exit_code)
{
	ft_printf("error_exit\n");
	perror(msg);
	exit(exit_code);
}

void	execute_command(char *command, char **env)
{
	char	**args;
	char	*path;

	ft_printf("execute_command\n");
	args = ft_split(command, ' ');
	path = get_command_path(args[0], env);
	if (!path)
	{
		ft_printf_fd(2, "%s : command not found\n", args[0]);
		free_array(args);
		exit(127);
	}
	if (execve(path, args, env) == -1)
	{
		perror("execve failed");
		if (path != args[0])
			free(path);
		free_array(args);
		error_exit("error executing command", 1);
	}
}

void	child(int pipe_fd[2], t_pipex_data *data)
{
	int	fd;

	ft_printf("child 1\n");
	fd = open(data->file1, O_RDONLY, 0644);
	if (fd < 0)
		error_exit("no such file or directory", 1);
	dup2(pipe_fd[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(pipe_fd[0]);
	execute_command(data->cmd1, data->envp);
}

void	parent(int pipe_fd[2], t_pipex_data *data)
{
	int	fd;

	ft_printf("parent\n");
	fd = open(data->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		error_exit("permission denied", 1);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(pipe_fd[1]);
	execute_command(data->cmd2, data->envp);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex_data	data;
	int				status;

	if (ac != 5)
		error_exit("usage: ./pipex file1 cmd1 cmd2 file2", 1);
	init_pipex_data(&data, av, envp);
	ft_printf("main\n");
	if (pipe(data.pipe_fd) < 0)
		error_exit("failed to create pipe", 1);
	data.pid = fork();
	if (data.pid < 0)
		error_exit("failed to fork first process", 1);
	if (data.pid == 0)
		child(data.pipe_fd, &data);
	waitpid(data.pid, &status, 0);
	if (status != 0)
	{
		ft_printf_fd(2, "First command failed, skipping second command\n");
		return (status);
	}
	parent(data.pipe_fd, &data);
	return (0);
}
