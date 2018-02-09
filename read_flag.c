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

int		read_flags_from_format(char *frm)
{
	t_flags		*tmp;
	char		*all_flags;
	int			count;

	all_flags = "#0-+ ";
	tmp = (t_flags *)malloc(sizeof(tmp));
	g_head = tmp;
	count = 0;
	clean_flags_struct();
	while (ft_strchr(all_flags, *frm) != 0)
	{
		if (*frm == '#')
			g_head->flag_hesh = 1;
		else if (*frm == '-')
			g_head->flag_minus = 1;
		else if (*frm == '+')
			g_head->flag_plus = 1;
		else if (*frm == '0')
			g_head->flag_zero = 1;
		else if (*frm == ' ')
			g_head->flag_space = 1;
		frm++;
		count++;
	}
	return (continue_with_width(frm, count));
}

int		continue_with_width(char *frm, int count)
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
	return (continue_with_precision(frm, count));
}

int		continue_with_precision(char *frm, int count)
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
	return (continue_with_size(frm, count));
}

/*
** Check and fix sizes later (if h and hh both will be used) 
*/

int		continue_with_size(char *frm, int count)
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
	return (count);
}

int		continue_with_conversions(char *frm, va_list ap)
{
	int		res_count;

	res_count = 0;
	g_head->conver_letter = *frm;
	if (*frm == 'd' || *frm == 'i' || *frm == 'D')
		res_count = print_D_d_i_conversions(ap);
	else if (*frm == 'u' || *frm == 'U')
		res_count = print_u_U_o_O_x_X_conversion(ap, 10, 0);
	else if (*frm == 'o' || *frm == 'O')
		res_count = print_u_U_o_O_x_X_conversion(ap, 8, 0);
	else if (*frm == 'x')
		res_count = print_u_U_o_O_x_X_conversion(ap, 16, 0);
	else if (*frm == 'X')
		res_count = print_u_U_o_O_x_X_conversion(ap, 16, 1);
	else if (*frm == 'S' || (*frm == 's' && g_head->size_l == 1))
		res_count = print_S_conversion(ap);
	else if (*frm == 's')
		res_count = print_s_conversion(ap);
	else if (*frm == 'C' || (*frm == 'c' && g_head->size_l == 1))
		res_count = print_C_conversion(ap);
	else if (*frm == 'c')
		res_count = print_c_conversion(ap);
	else if (*frm == 'p')
		res_count = print_p_conversion(ap, 16, 0);
	else if (*frm == '%')
		res_count = print_percent_conversion();
	else
	{
		ft_putchar(*frm); // must be changed later
		res_count++;
	}
	return (res_count);
}
