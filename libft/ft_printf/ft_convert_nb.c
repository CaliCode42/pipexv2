/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:08:12 by tcali             #+#    #+#             */
/*   Updated: 2025/03/25 23:56:33 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_signed(t_printf *list)
{
	long	nb_long;

	nb_long = va_arg(list->ap, int);
	if (nb_long < 0)
	{
		list->format.is_negative = 1;
		nb_long = -nb_long;
	}
	list->format.base = "0123456789";
	if (list->format.itoa)
		free(list->format.itoa);
	list->format.itoa = ft_itoa_base(list, nb_long);
	if (!list->format.itoa)
		return ;
}

static void	ft_print_unsigned(t_printf *list)
{
	unsigned int	nb_unint;

	nb_unint = va_arg(list->ap, unsigned int);
	list->format.base = "0123456789";
	if (list->format.itoa)
		free(list->format.itoa);
	list->format.itoa = ft_itoa_base(list, nb_unint);
	if (!list->format.itoa)
		return ;
}

static void	ft_print_void(t_printf *list)
{
	void			*ptr;

	ptr = va_arg(list->ap, void *);
	if (list->format.itoa)
		free(list->format.itoa);
	if (ptr == 0)
	{
		ft_strcpy(list, "(nil)");
		list->format.hash = 0;
		list->format.lowercase = 0;
		list->format.zero_pad = 0;
		return ;
	}
	list->format.itoa = ft_itoa_base(list, (unsigned long)ptr);
	if (!list->format.itoa)
		return ;
}

static void	ft_print_hexa(t_printf *list)
{
	unsigned int	nb_hexa;

	nb_hexa = va_arg(list->ap, unsigned int);
	if (list->format.itoa)
		free(list->format.itoa);
	if (nb_hexa == 0)
	{
		ft_strcpy(list, "0");
		list->format.hash = 0;
		list->format.lowercase = 0;
		list->format.zero_pad = 0;
		return ;
	}
	list->format.itoa = ft_itoa_base(list, nb_hexa);
	if (!list->format.itoa)
		return ;
}

void	ft_convert_nb(t_printf *list, char speci)
{
	if (ft_present("di", speci))
		ft_print_signed(list);
	else if (ft_present("u", speci))
		ft_print_unsigned(list);
	else if (speci == 'p')
		ft_print_void(list);
	else if (ft_present("xX", speci))
		ft_print_hexa(list);
}
