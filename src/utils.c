/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:48:52 by tcali             #+#    #+#             */
/*   Updated: 2025/04/10 20:48:52 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(const char *msg, int exit_code)
{
	perror(msg);
	exit(exit_code);
}

void	init_pipex_data(t_pipex_data *data, char **av, char **env)
{
	data->pid1 = 0;
	data->pid2 = 0;
	data->cmd1 = av[2];
	data->cmd2 = av[3];
	if (data->cmd2 == NULL || data->cmd2[0] == '\0')
	{
		write(2, "pipex: empty command\n", 22);
		exit(EXIT_FAILURE);
	}
	data->envp = env;
	data->file1 = av[1];
	data->file2 = av[4];
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

char	*find_command(char *cmd, char **path)
{
	char	*cmd_path;
	int		i;

	i = 0;
	while (path[i])
	{
		cmd_path = ft_str_threejoin(path[i], "/", cmd);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

char	*get_command_path(char *cmd, char **env)
{
	char	**path;
	char	*bin;
	int		i;

	if (cmd[0] == '/')
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	i = 0;
	while (ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	path = ft_split(env[i] + 5, ':');
	bin = find_command(cmd, path);
	if (!bin)
	{
		free_array(path);
		return (NULL);
	}
	return (bin);
}
