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
// #include <stdio.h>
// #include <stdlib.h>

// char	*ft_strdup(const char *s1)
// {
// 	int		len;
// 	int		i;
// 	char	*res;

// 	len = 0;
// 	i = 0;
// 	while (s1[len] != '\0')
// 		len++;
// 	res = (char*)malloc(sizeof(char) * (len + 1));
// 	if (res == NULL)
// 		return (NULL);
// 	while (s1[i] != '\0')
// 	{
// 		res[i] = s1[i];
// 		i++;
// 	}
// 	res[i] = '\0';
// 	return (res);
// }

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

char	*itoa_base_unsign(size_t nb, int base, int upper_case)
{
	char		*res;
	int			len;

	len = ft_intlen(nb, base);
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nb == 0)
		res[0] = '0';
	res[len] = '\0';
	while (len--)
	{
		if (nb % base < 10)
			res[len] = (nb % base) + 48;
		else
			res[len] = (nb % base) - 10 + (upper_case ? 65 : 97);
		if (nb >= base)
			nb /= base;
	}
	return (res);
}

char	*itoa_base_sign(long long int nb)
{
	char		*res;
	size_t		len;

	if (nb == -9223372036854775807)
		return (ft_strdup("-9223372036854775807"));
	len = (nb < 0) ? ft_intlen(-nb, 10) : ft_intlen(nb, 10);
	if (nb < 0)
		len++;
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	res[len] = '\0';
	while (nb)
	{
		len--;
		res[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}

// int 	main(void)
// {
// 	char	*nb;

// 	nb = itoa_base_sign(1);
// 	printf("%s\n", nb);
// 	return (0);
// }
