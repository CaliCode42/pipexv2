/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:58:35 by tcali             #+#    #+#             */
/*   Updated: 2025/04/04 18:55:58 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	ft_free_set_null(char **s1)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
}

//read from file and copy data into buffer. Stop when \n present in buffer.
char	*read_file(int fd, char *buffer)
{
	int		bytes_read;
	char	*tmp_buf;
	int		found_nl;

	bytes_read = 1;
	found_nl = 0;
	if (!buffer)
		buffer = ft_strdup_gnl("");
	tmp_buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp_buf)
		return (NULL);
	while (bytes_read > 0 && found_nl == 0)
	{
		bytes_read = read(fd, tmp_buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(tmp_buf), NULL);
		tmp_buf[bytes_read] = '\0';
		buffer = join_free(buffer, tmp_buf);
		if (!buffer)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			found_nl = 1;
	}
	free(tmp_buf);
	return (buffer);
}

//copy buffer into line up to the \n.
char	*ft_parse_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

//fetch buffer to a new_line so that buffer can be free.
char	*ft_new_line(char *buffer)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	new_line = NULL;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	new_line = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_line[j++] = buffer[i++];
	new_line[j++] = '\0';
	return (free(buffer), new_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_free_set_null(&buffer[fd]), NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_parse_line(buffer[fd]);
	if (!line)
		return (ft_free_set_null(&buffer[fd]), NULL);
	buffer[fd] = ft_new_line(buffer[fd]);
	if (!buffer[fd])
		ft_free_set_null(&buffer[fd]);
	return (line);
}
//int main(int argc, char **argv)
//{
//	int		fd;
//	char	*line;
//	int		count;
//
//	if (argc != 2)
//	{
//		printf("Usage: %s <filename>\n", argv[0]);
//		return (1);
//	}
//	fd = open(argv[1], O_RDONLY);
//	if (fd == -1)
//	{
//		perror("Error opening file");
//		return (1);
//	}
//	count = 0;
//	while ((line = get_next_line(fd)) != NULL)
//	{
//		count++;
//		printf("%d : [%s]\n", count, line);
//		free(line);
//	}
//	close(fd);
//	return (0);
//}
