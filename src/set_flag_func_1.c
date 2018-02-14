/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag_func1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:00:49 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/14 11:00:51 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*set_flag_for_d_i_u(char *res)
{
	if (g_head->flag_plus == 1)
		res = set_plus_flag(res);
	else if (g_head->flag_space == 1)
		res = set_space_flag(res);
	if (g_head->width > 0)
	{
		if (g_head->flag_minus == 1)
		{
			res = set_minus_flag(res);
			g_head->flag_zero = 0;
		}
		else if (g_head->flag_zero == 1 && g_head->precision_flag == 0)
			res = set_zero_flag(res);
		else
			g_head->flag_zero = 0;
	}
	return (res);
}

char	*set_flag_for_o_x_X(char *res)
{
	if (g_head->width > 0)
		if (g_head->flag_zero == 1 && g_head->precision_flag == 0
			&& g_head->flag_minus == 0)
			res = set_zero_flag(res);
	if (g_head->flag_hesh == 1 && (g_head->conver_letter == 'o' ||
		g_head->conver_letter == 'O'))
		res = set_hesh_flag_for_octal(res);
	else if ((g_head->flag_hesh == 1 && g_head->conver_letter == 'x') ||
		g_head->conver_letter == 'p')
		res = set_hesh_flag_for_hexadecimal_x(res);
	else if (g_head->flag_hesh == 1 && g_head->conver_letter == 'X')
		res = set_hesh_flag_for_hexadecimal_X(res);
	if (g_head->flag_minus == 1)
			res = set_minus_flag(res);
	return (res);
}

char	*set_flag_for_s(char *res)
{
	/* necessary for this implemenation (see set_minus_flag function) */
	g_head->flag_space = 0;
	if (g_head->width > 0)
	{
		if (g_head->flag_minus == 1)
			res = set_minus_flag(res);
		else if (g_head->flag_zero == 1)
			res = set_zero_flag_for_s(res);
	}
	return (res);
}

int		set_flag_for_c(char *width, char value, int width_len, int i)
{
	if (width_len <= 1)
	{
		ft_putchar(value);
		return (1);
	}
	else
	{
		if (g_head->flag_minus == 1)
		{
			ft_putchar(value);
			ft_putstr(width + 1);
		}
		else if (g_head->flag_zero == 1)
		{
			while (width_len - 1 > i++)
				ft_putchar('0');
			ft_putchar(value);
		}
		else
		{
			ft_putstr(width + 1);
			ft_putchar(value);
		}
	}
	return (width_len);
}
