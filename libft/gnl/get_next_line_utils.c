/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:58:48 by tcali             #+#    #+#             */
/*   Updated: 2025/04/01 16:56:21 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

// int	ft_strlen(const char *s)
// {
	// int	len;

	// len = 0;
	// while (s[len])
		// len++;
	// return (len);
// }

/*char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}*/

char	*ft_strdup_gnl(const char *source)
{
	int		i;
	char	*copy;

	if (!source)
		return (NULL);
	i = 0;
	copy = malloc (sizeof(char) * (ft_strlen(source) + 1));
	if (!copy)
		return (NULL);
	while (source[i])
	{
		copy[i] = source[i];
		i++;
	}
	if (source[i] == '\n')
	{
		copy[i] = '\n';
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin_gnl(const char *s1, char const *s2)
{
	int		total_len;
	int		i;
	int		j;
	char	*joined;

	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(sizeof(char) * (total_len + 1));
	if (!joined || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		joined[i] = s2[j];
		i++;
		j++;
	}
	joined[total_len] = 0;
	return (joined);
}

char	*join_free(char *buffer, char *tmp_buf)
{
	char	*temp;

	temp = ft_strjoin_gnl(buffer, tmp_buf);
	free(buffer);
	return (temp);
}
