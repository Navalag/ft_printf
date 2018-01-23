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

#include "ft_printf.h"

char	*set_precision(char *res)
{
	char	*res_prec;
	int		diff;

	if (g_head->width < g_head->precision)
	{
		free(res);
		res_prec = (char *)malloc(g_head->precision + 1);
		res_prec = ft_memset(res_prec, '0', g_head->precision);
		res_prec[g_head->precision] = '\0';
		return (res_prec);
	}
	else
	{
		diff = g_head->width - g_head->precision;
		ft_memset(res + diff, '0', g_head->precision);
	}
	return (res);
}

char	*set_width(int prec_y_n)
{
	char	*res;

	res = (char *)malloc(g_head->width + 1);
	res = ft_memset(res, ' ', g_head->width);
	res[g_head->width] = '\0';
	return ((prec_y_n) ? set_precision(res) : res);
}
