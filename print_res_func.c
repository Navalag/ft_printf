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

void	print_s_conversion(va_list ap)
{
	char	*res;
	char	*s_val;

	res = set_width(0);
	s_val = cast_s_size(ap);
	if (ft_strlen(res) <= ft_strlen(s_val))
	{
		free(res);
		if (g_head->precision_flag)
		{
			while (*s_val && g_head->precision >= 0)
			{
				ft_putchar(*s_val);
				g_head->precision--;
				s_val++;
			}
		}
		else
			while (*s_val)
			{
				ft_putchar(*s_val);
				s_val++;
			}
	}
	else
		print_s_continue(s_val, res);
}

void	print_s_continue(char *s_val, char *res)
{
	int		res_len;
	int		s_val_len;

	res_len = ft_strlen(res);
	s_val_len = ft_strlen(s_val);
	if (g_head->precision_flag)
	{
		while (res_len > g_head->precision)
		{
			ft_putchar(*res);
			res++;
			res_len--;
		}
		while (*s_val && g_head->precision > 0)
		{
			ft_putchar(*s_val);
			g_head->precision--;
			s_val++;
		}
	}
	else
	{
		while (res_len > s_val_len)
		{
			ft_putchar(*res);
			res++;
			res_len--;
		}
		while (*s_val && s_val_len > 0)
		{
			ft_putchar(*s_val);
			s_val_len--;
			s_val++;
		}
	}
}

void	print_c_conversion(va_list ap)
{
	char	*res;
	char	c_val;

	res = set_width(0);
	c_val = cast_c_size(ap);
	if (ft_strlen(res) <= 1)
	{
		free(res);
		ft_putchar(c_val);
	}
	else
	{
		while (ft_strlen(res) > 1) // can be optimized with strlen
		{
			ft_putchar(*res);
			res++;
		}
		ft_putchar(c_val);
	}
}

void	print_C_conversion(va_list ap)
{
	char		*res;
	wchar_t		C_val;

	res = set_width(0);
	C_val = cast_C_size(ap);
	if (ft_strlen(res) <= 1)
	{
		free(res);
		print_unicode((unsigned int)C_val);
	}
	else
	{
		while (ft_strlen(res) > 1) // can be optimized with strlen
		{
			ft_putchar(*res);
			res++;
		}
		print_unicode((unsigned int)C_val);
	}
}

void	print_S_conversion(va_list ap)
{
	char		*res;
	wchar_t		*S_val;
	int			res_len;
	int			S_val_len;

	res = set_width(0);
	S_val = cast_S_size(ap);
	res_len = ft_strlen(res);
	S_val_len = ft_intlen((size_t)S_val, 10);
	if (res_len <= S_val_len)
	{
		free(res);
		while (*S_val)
		{
			print_unicode((unsigned int)*S_val);
			S_val++;
		}
	}
	else
	{
		while (res_len > S_val_len)
		{
			ft_putchar(*res);
			res++;
			res_len--;
		}
		while (*S_val)
		{
			print_unicode((unsigned int)*S_val);
			S_val++;
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
