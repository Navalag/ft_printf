/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:18:31 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/11 16:18:35 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_copy;

	b_copy = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b_copy[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

char	*set_precision(char *res, int width, int precision)
{
	char	*res_prec;
	int		diff;

	if (width < precision)
	{
		free(res);
		res_prec = (char *)malloc(precision + 1);
		res_prec = ft_memset(res_prec, '0', precision);
		res_prec[precision] = '\0';
		return (res_prec);
	}
	else
	{
		diff = width - precision;
		ft_memset(res + diff, '0', precision);
	}
	return (res);
}

char	*set_width(int width, int precision)
{
	char	*res;

	if (width > 0)
	{
		res = (char *)malloc(width + 1);
		res = ft_memset(res, ' ', width);
		res[width] = '\0';
	}
	return (set_precision(res, width, precision));
}

int		set_size(int convercision, char *size)
{
	if (*size == 'h' && *(size + 1) == 'h')
		return (short short int)convercision;
	else if (*size == 'h' && *(size + 1) != 'h')
		return (short int)convercision;
	else if (*size == 'l' && *(size + 1) == 'l')
		return (long long int)convercision;
	else if (*size == 'l' && *(size + 1) != 'l')
		return (long int)convercision;
	return (convercision);
}

int		main(void)
{
	int		width = 6;
	int		precision = 7;

	char	*res = set_width(width, precision);
	printf("%s\n", res);
	char	*size = "h";
	short int		convercision = set_size(123, size);
	printf("%hi\n", convercision);
}
