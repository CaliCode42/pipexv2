/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:36:22 by tcali             #+#    #+#             */
/*   Updated: 2025/03/25 23:38:15 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/libft.h"

int	ft_nb_len(long nb)
{
	int	nb_len;

	nb_len = 1;
	if (nb < 0)
	{
		nb_len++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		nb_len++;
		nb = nb / 10;
	}
	return (nb_len);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	n_len;
	char	*result;

	nb = n;
	n_len = ft_nb_len(nb);
	result = malloc(sizeof(char) * n_len + 1);
	if (!result)
		return (NULL);
	result[n_len] = '\0';
	if (nb == -2147483647)
		result = "-2147483647";
	if (nb < 0)
	{
		result[0] = '-';
		nb *= -1;
	}
	while (nb >= 10)
	{
		result[--n_len] = (nb % 10) + '0';
		nb /= 10;
	}
	result[--n_len] = (nb % 10) + '0';
	return (result);
}
