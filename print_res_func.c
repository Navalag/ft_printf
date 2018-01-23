/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 10:30:07 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/23 10:30:09 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* manage liks with ival */

void	print_d_i_conversions(va_list ap)
{
	char	*res;
	char	*ival;

	res = set_width(1);
	ival = cast_d_i_size(ap);
	if (ft_strlen(res) <= ft_strlen(ival))
	{
		free(res);
		ft_putstr(ival);
	}
	else
	{
		while (ft_strlen(res) > ft_strlen(ival)) // can be optimized with strlen
		{
			ft_putchar(*res);
			res++;
		}
		while (*ival)
		{
			ft_putchar(*ival);
			ival++;
		}
	}
}

void	print_u_U_o_O_x_X_conversion(va_list ap, int base, int up_case)
{
	char	*res;
	char	*u_val;

	res = set_width(1);
	u_val = cast_u_U_o_O_x_X_size(ap, base, up_case);
	if (ft_strlen(res) <= ft_strlen(u_val))
	{
		free(res);
		ft_putstr(u_val);
	}
	else
	{
		while (ft_strlen(res) > ft_strlen(u_val)) // can be optimized with strlen
		{
			ft_putchar(*res);
			res++;
		}
		while (*u_val)
		{
			ft_putchar(*u_val);
			u_val++;
		}
	}
}

/* check res without width later! */

void	print_percent_conversion()
{
	char	*res;
	int		res_len;

	res = set_width(0);
	if (*res)
	{
		res_len = ft_strlen(res);
		res[res_len - 1] = '%';
		ft_putstr(res);
	}
	else
		ft_putchar('%');
}
