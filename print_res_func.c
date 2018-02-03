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

char	*generate_res_str(char *width, char *value)
{
	char	*res;
	int		width_len;
	int		value_len;
	int		i;

	width_len = ft_strlen(width);
	value_len = ft_strlen(value);
	i = 0;
	if (width_len <= value_len)
		res = value;
	else
	{
		while (value_len && value[value_len - 1] != '-')
			width[--width_len] = value[--value_len];
		while (width[i] && width[i] == ' ' && width[i + 1] == ' ')
			i++;
		if (width[i] == ' ' && value[0] == '-')
		{
			width[i] = '-';
			res = width;
		}
		else if (width[i] != ' ' && value[0] == '-')
			res = ft_strjoin("-", width);
		else
			res = width;
	}
	return (res);
}

char	*generate_res_str_for_s(char *width, char *value)
{
	char	*res;
	int		width_len;
	int		value_len;
	int		i;

	width_len = ft_strlen(width);
	value_len = ft_strlen(value);
	i = 0;
	if (width_len <= value_len)
	{
		if (g_head->precision >= value_len)
			res = value;
		else
			res = ft_strncpy(value, value, g_head->precision);
	}
	else
	{
		while (width_len > value_len || width_len > g_head->precision)
		{
			i++;
			width_len--;
		}
		if (g_head->precision_flag == 1)
			ft_strncpy(width + i, value, g_head->precision);
		else
			ft_strcpy(width + i, value);
		res = width;
	}
	return (res);
}

/* manage liks with ival */

void	print_D_d_i_conversions(va_list ap)
{
	char	*width;
	char	*value;
	char	*res;
	int		res_len;

	width = set_width(1);
	value = cast_D_d_i_size(ap);
	res = set_flag_for_d_i_u(generate_res_str(width, value));
	res_len = ft_strlen(res);
	ft_putstr(res);
}

void	print_u_U_o_O_x_X_conversion(va_list ap, int base, int up_case)
{
	char	*width;
	char	*value;
	char	*res;
	int		res_len;

	width = set_width(1);
	value = cast_u_U_o_O_x_X_size(ap, base, up_case);
	res = set_flag_for_o_x_X(generate_res_str(width, value));
	res_len = ft_strlen(res);
	ft_putstr(res);
}

void	print_s_conversion(va_list ap)
{
	char	*width;
	char	*value;
	char	*res;
	int		res_len;

	width = set_width(0);
	value = cast_s_size(ap);
	res = set_flag_for_s(generate_res_str_for_s(width, value));
	res_len = ft_strlen(res);
	ft_putstr(res);
}

void	print_c_conversion(va_list ap)
{
	char	*width;
	char	value;
	int		width_len;
	int		res_len;

	width = set_width(0);
	value = cast_c_size(ap);
	width_len = ft_strlen(width);
	res_len = set_flag_for_c(width, value, width_len, 0);
	printf("\n%i\n", res_len);
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
