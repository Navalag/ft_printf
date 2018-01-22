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

void	read_flags_from_format(char *frm, va_list ap)
{
	t_flags		tmp;
	char		*all_flags;

	all_flags = "#0-+ ";
	// if ((tmp = (t_flags *)malloc(sizeof(*tmp))) == NULL)
	// 	return ;
	g_head = &tmp;
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
	}
	continue_with_width(frm, ap);
}

void	continue_with_width(char *frm, va_list ap)
{
	int		res;

	res = 0;
	while (*frm >= '0' && *frm <= '9')
	{
		res = res * 10 + *frm - '0';
		frm++;
	}
	g_head->width = res;
	continue_with_precision(frm, ap);
}

void	continue_with_precision(char *frm, va_list ap)
{
	int		res;

	res = 0;
	if (*frm == '.')
	{
		frm++;
		while (*frm >= '0' && *frm <= '9')
		{
			res = res * 10 + *frm - '0';
			frm++;
		}
	}
	g_head->precision = res;
	continue_with_size(frm, ap);
}

void	continue_with_size(char *frm, va_list ap)
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
	}
	continue_with_conversions(frm, ap);
}

void	continue_with_conversions(char *frm, va_list ap)
{
	char	*res;
	char	*ival;

	if ((*frm == 'd' || *frm == 'i') )
	{
		res = set_width();
		ival = cast_with_size(ap);
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
}
