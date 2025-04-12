/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:59:00 by tcali             #+#    #+#             */
/*   Updated: 2025/04/01 16:56:17 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

char	*get_next_line(int fd);

//size_t	ft_strlen(const char *str);
//char	*ft_strchr(const char *s, int c);
char	*ft_strdup_gnl(const char *source);
char	*ft_strjoin_gnl(const char *s1, const char *s2);
char	*join_free(char *buffer, char *tmp_buf);

#endif