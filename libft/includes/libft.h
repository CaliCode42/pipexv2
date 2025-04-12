/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:02:06 by tcali             #+#    #+#             */
/*   Updated: 2025/04/12 19:01:41 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdarg.h>
# include "../includes/ft_printf.h"
# include "../includes/get_next_line.h"

typedef struct s_content
{
	int			nb;
	int			index;
	int			order;
}				t_content;

typedef struct s_list
{
	char			stack;
	t_content		content;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

// Part 1 - Libfc Functions
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc( size_t elementCount, size_t elementSize );
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *ptr, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *source);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strsep(char **str_ptr, const char *sep);
size_t	ft_strcspn(const char *str, const char *sep);
int		ft_sprintf(char *str, const char *format, ...);
/* ************************************************************************** */
//Part 2 - Additional Functions
char	*ft_itoa(int n);
void	ft_putchar_fd(int fd, char c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
/* ************************************************************************** */
//Bonus Part
t_list	*ft_lstnew(t_content content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(t_content));
void	ft_lstclear(t_list **lst, void (*del)(t_content));
void	ft_lstiter(t_list *lst, t_content (*f)(t_content));
t_list	*ft_lstmap(t_list *lst, t_content (*f)(t_content),
			void (*del)(t_content));

#endif