/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:54:06 by tcali             #+#    #+#             */
/*   Updated: 2025/04/10 21:54:06 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "../libft/includes/libft.h"

typedef struct s_pipex_data
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd1;
	char	*cmd2;
	char	**envp;
	char	*file1;
	char	*file2;
}		t_pipex_data;

// Error handling
void	error_exit(const char *msg, int exit_code);

// Process handling
void	execute_command(char *cmd, char **env);
void	child(int pipe_fd[2], t_pipex_data *data);
void	parent(int pipe_fd[2], t_pipex_data *data);

// Utility functions
void	free_array(char **array);
char	*get_command_path(char *cmd, char **env);
void	init_pipex_data(t_pipex_data *data, char **av, char **env);
char	*ft_str_threejoin(char const *s1, char const *s2, char const *s3);

#endif 