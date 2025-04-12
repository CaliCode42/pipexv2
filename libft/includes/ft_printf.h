/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:24:18 by tcali             #+#    #+#             */
/*   Updated: 2025/04/10 20:58:14 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../includes/libft.h"

typedef struct s_format
{
	int		left_justif;
	int		zero_pad;
	int		plus;
	int		space;
	int		hash;
	char	specifier;
	int		width;
	int		precision;
	int		lowercase;
	int		uppercase;
	char	*base;
	char	*itoa;
	char	*str;
	int		is_negative;
	char	pad;
	int		prefix_checked;
	int		is_malloc;
}				t_format;

typedef struct s_printf
{
	const char	*str;
	va_list		ap;
	int			nb_chars;
	char		*ptr;
	t_format	format;
	int			fd;
}				t_printf;

typedef struct s_sprintf
{
	char		*str;
	const char	*format;
	va_list		ap;
	int			len;
	char		*result;
}	t_sprintf;

int		ft_printf(const char *format, ...);
int		ft_printf_fd(int fd, const char *format, ...);
int		ft_parse_format(t_printf *list);
void	*ft_memset(void *s, int c, size_t n);
int		ft_atoi_base(t_printf *list);
void	ft_render_format(t_printf *list);
int		ft_present(const char *str, char c);
void	ft_printchar(t_printf *list, int c, char pad);
void	ft_printstr(t_printf *list, char *str);
void	ft_check_prefix(t_printf *list);
void	ft_check_width(t_printf *list);
void	ft_putstr(t_printf *list, char *str);
void	ft_check_precision(t_printf *list, char *str);
void	ft_pickstr(t_printf *list);
void	ft_fill_withzero(char *str, size_t n);
void	ft_update_itoa(t_printf *list, char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_print_nb(t_printf *list, char speci);
void	ft_convert_nb(t_printf *list, char speci);
char	*ft_itoa_base(t_printf *list, unsigned long nb);
int		ft_strcpy(t_printf *list, char *src);
int		ft_strlen_int(const char *str);
void	ft_free(t_printf *list, char *str);
void	ft_putchar(char c);
void	ft_putformat(t_printf *list, char c);

//ft_sprintf
int		ft_sprintf(char *str, const char *format, ...);
char	*ft_process_format(t_sprintf *s);
char	*ft_handle_format(t_sprintf *s, int *i);
char	*ft_handle_char(t_sprintf *s);
char	*ft_handle_string(t_sprintf *s);
char	*ft_handle_int(t_sprintf *s);
char	*ft_handle_unsigned(t_sprintf *s);
char	*ft_handle_hex(t_sprintf *s);
char	*ft_handle_pointer(t_sprintf *s);
char	*ft_handle_percent(void);
char	*ft_append_char(t_sprintf *s, char c);

//ft_snprintf
int		ft_snprintf(char *str, size_t size, const char *format, ...);

#endif