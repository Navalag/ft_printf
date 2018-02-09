/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:46:17 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/23 11:46:20 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(size_t nb, int base)
{
	int		len;

	len = 0;
	if (nb <= 0)
		len = 1;
	while (nb != 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char	*itoa_base_unsign(size_t nb, int base, int up_case)
{
	char	*res;
	int		len;
	char	*symb_lower;
	char	*symb_upper;

	len = ft_intlen(nb, base);
	symb_lower = "0123456789abcdef";
	symb_upper = "0123456789ABCDEF";
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nb == 0)
		res[0] = '0';
	res[len] = '\0';
	while (len--)
	{
		res[len] = (up_case) ? symb_upper[nb % base] : symb_lower[nb % base];
		nb /= base;
	}
	return (res);
}

char	*itoa_base_sign(intmax_t nb)
{
	char		*res;
	uintmax_t	nb_copy;
	size_t		len;

	nb_copy = (nb < 0) ? -nb : nb;
	len = ft_intlen(nb_copy, 10);
	if (nb < 0)
		len++;
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nb_copy == 0)
		res[0] = '0';
	if (nb < 0)
		res[0] = '-';
	res[len] = '\0';
	while (nb_copy)
	{
		res[--len] = (nb_copy % 10) + '0';
		nb_copy /= 10;
	}
	return (res);
}
