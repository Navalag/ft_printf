/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:44:14 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/14 11:44:17 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clean_flags_struct()
{
	g_head->flag_hesh = 0;
	g_head->flag_minus = 0;
	g_head->flag_plus = 0;
	g_head->flag_zero = 0;
	g_head->flag_space = 0;
	g_head->width = 0;
	g_head->precision = 0;
	g_head->precision_flag = 0;
	g_head->size_hh = 0;
	g_head->size_h = 0;
	g_head->size_ll = 0;
	g_head->size_l = 0;
	g_head->size_j = 0;
	g_head->size_z = 0;
	g_head->conver_letter = 0;
}

int		read_flags_from_format(char *frm, va_list ap)
{
	t_flags		tmp;
	char		*all_flags;
	int			count;

	all_flags = "#0-+ ";
	g_head = &tmp;
	count = 0;
	clean_flags_struct();
	while (ft_strchr(all_flags, *frm) != 0)
	{
		if (*frm == '#')
			tmp.flag_hesh = 1;
		else if (*frm == '-')
			tmp.flag_minus = 1;
		else if (*frm == '+')
			tmp.flag_plus = 1;
		else if (*frm == '0')
			tmp.flag_zero = 1;
		else if (*frm == ' ')
			tmp.flag_space = 1;
		frm++;
		count++;
	}
	return (continue_with_width(frm, ap, count));
}

int		continue_with_width(char *frm, va_list ap, int count)
{
	int		res;

	res = 0;
	while (*frm >= '0' && *frm <= '9')
	{
		res = res * 10 + *frm - '0';
		frm++;
		count++;
	}
	g_head->width = res;
	return (continue_with_precision(frm, ap, count));
}

int		continue_with_precision(char *frm, va_list ap, int count)
{
	int		res;

	res = 0;
	if (*frm == '.')
	{
		frm++;
		count++;
		g_head->precision_flag = 1;
		while (*frm >= '0' && *frm <= '9')
		{
			res = res * 10 + *frm - '0';
			frm++;
			count++;
		}
	}
	g_head->precision = res;
	return (continue_with_size(frm, ap, count));
}

/*
** later need to add a ficha with more and less important sizes.
** Check this func later and fix it!!!
*/

int		continue_with_size(char *frm, va_list ap, int count)
{
	char	*all_sizes;

	all_sizes = "hljz";
	while (ft_strchr(all_sizes, *frm) != 0)
	{
		if (*frm == 'h' && *(frm + 1) == 'h')
			g_head->size_hh = 1;
		else if (*frm == 'h' && *(frm + 1) != 'h')
			g_head->size_h = 1;
		else if (*frm == 'l' && *(frm + 1) == 'l')
			g_head->size_ll = 1;
		else if (*frm == 'l' && *(frm + 1) != 'l')
			g_head->size_l = 1;
		else if (*frm == 'j')
			g_head->size_j = 1;
		else if (*frm == 'z')
			g_head->size_z = 1;
		frm++;
		count++;
	}
	return (continue_with_conversions(frm, ap, count));
}

int		continue_with_conversions(char *frm, va_list ap, int count)
{
	g_head->conver_letter = *frm;
	if (*frm == 'd' || *frm == 'i' || *frm == 'D')
		print_D_d_i_conversions(ap);
	else if (*frm == 'u' || *frm == 'U')
		print_u_U_o_O_x_X_conversion(ap, 10, 0);
	else if (*frm == 'o' || *frm == 'O')
		print_u_U_o_O_x_X_conversion(ap, 8, 0);
	else if (*frm == 'x')
		print_u_U_o_O_x_X_conversion(ap, 16, 0);
	else if (*frm == 'X')
		print_u_U_o_O_x_X_conversion(ap, 16, 1);
	else if (*frm == 's')
		print_s_conversion(ap);
	else if (*frm == 'S')
		print_S_conversion(ap);
	else if (*frm == 'c')
		print_c_conversion(ap);
	else if (*frm == 'C')
		print_C_conversion(ap);
	else if (*frm == '%')
		print_percent_conversion();
	return (++count);
}
