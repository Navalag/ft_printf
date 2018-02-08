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

char	*generate_res_for_int(char *width, char *value)
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

char	*generate_res_for_str(char *width, char *value)
{
	char	*res;
	int		width_len;
	int		value_len;
	int		i;

	width_len = ft_strlen(width);
	value_len = ft_strlen(value);
	i = 0;
	if (width_len <= value_len && g_head->precision >= value_len
		&& g_head->precision_flag)
			res = value;
	else if (g_head->precision < value_len && g_head->precision > width_len)
		res = ft_strsub(value, 0, g_head->precision);
	else
	{
		while (width_len > value_len || 
			(g_head->precision_flag && width_len > g_head->precision))
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

int		ft_utf_strlen(wchar_t *value)
{
	int		len;
	int		bin_len;

	len = 0;
	while (*value)
	{
		bin_len = find_bin_size(*value);
		if (bin_len <= 7)
			len++;
		else if (bin_len <= 11)
			len += 2;
		else if (bin_len <= 16)
			len += 3;
		else
			len += 4;
		value++;
	}
	return (len);
}

int		generate_and_print_utf_str(char *width, wchar_t *value)
{
	int		width_len;
	int		value_len;

	width_len = ft_strlen(width);
	value_len = ft_utf_strlen(value);
	if (width_len <= value_len)
		while (*value)
			print_unicode((unsigned int)*value++);
	else if (g_head->flag_minus == 1)
	{
		while (*value)
			print_unicode((unsigned int)*value++);
		while (width_len-- > value_len)
			ft_putchar(' ');
	}
	else
	{
		while (width_len-- > value_len)
			ft_putchar(' ');
		while (*value)
			print_unicode((unsigned int)*value++);
	}
	return ((width_len <= value_len) ? value_len : width_len);
}

int		ft_utf_charlen(wchar_t value)
{
	int		bin_len;

	bin_len = find_bin_size(value);
	if (bin_len <= 7)
		return (1);
	else if (bin_len <= 11)
		return (2);
	else if (bin_len <= 16)
		return (3);
	else
		return (4);
}

int		generate_and_print_utf_char(char *width, wchar_t value)
{
	int		width_len;
	int		value_len;

	width_len = ft_strlen(width);
	value_len = ft_utf_charlen(value);
	if (width_len <= value_len)
		print_unicode((unsigned int)value);
	else if (g_head->flag_minus == 1)
	{
		print_unicode((unsigned int)value);
		while (width_len-- > value_len)
			ft_putchar(' ');
	}
	else
	{
		while (width_len-- > value_len)
			ft_putchar(' ');
		print_unicode((unsigned int)value);
	}
	return ((width_len <= value_len) ? value_len : width_len);
}

/* manage liks with ival */

int		print_D_d_i_conversions(va_list ap)
{
	char	*width;
	char	*value;
	char	*res;
	int		res_len;

	width = set_width(1);
	value = cast_D_d_i_size(ap);
	res = set_flag_for_d_i_u(generate_res_for_int(width, value));
	res_len = ft_strlen(res);
	ft_putstr(res);
	return (res_len);
}

int		print_u_U_o_O_x_X_conversion(va_list ap, int base, int up_case)
{
	char	*width;
	char	*value;
	char	*res;
	int		res_len;

	width = set_width(1);
	value = cast_u_U_o_O_x_X_size(ap, base, up_case);
	if (value[0] == '0')
	{
		if (g_head->precision_flag == 1 && g_head->precision == 0)
			res = width;
		else
		{
			ft_putchar('0');
			return (1);
		}
	}
	else
		res = set_flag_for_o_x_X(generate_res_for_int(width, value));
	res_len = ft_strlen(res);
	ft_putstr(res);
	return (res_len);
}

int		print_s_conversion(va_list ap)
{
	char	*width;
	char	*value;
	char	*res;
	int		res_len;

	width = set_width(0);
	value = cast_s_size(ap);
	if (value == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
		res = set_flag_for_s(generate_res_for_str(width, value));
	res_len = ft_strlen(res);
	ft_putstr(res);
	return (res_len);
}

int		print_S_conversion(va_list ap)
{
	char			*width;
	wchar_t			*value;
	int				res_len;

	width = set_width(0);
	value = cast_S_size(ap);
	res_len = generate_and_print_utf_str(width, value);
	return (res_len);
}

int		print_c_conversion(va_list ap)
{
	char	*width;
	char	value;
	int		width_len;
	int		res_len;

	width = set_width(0);
	value = cast_c_size(ap);
	width_len = ft_strlen(width);
	res_len = set_flag_for_c(width, value, width_len, 0);
	return (res_len);
}

int		print_C_conversion(va_list ap)
{
	char	*width;
	wchar_t	value;
	int		res_len;

	width = set_width(0);
	value = cast_C_size(ap);
	res_len = generate_and_print_utf_char(width, value);
	return (res_len);
}

int		print_p_conversion(va_list ap, int base, int up_case)
{
	char	*width;
	char	*value;
	char	*res;
	int		res_len;

	width = set_width(1);
	value = cast_p_size(ap, base, up_case);
	g_head->flag_hesh = 1;
	g_head->conver_letter = 'x';
	res = set_flag_for_o_x_X(generate_res_for_int(width, value));
	res_len = ft_strlen(res);
	ft_putstr(res);
	return (res_len);
}

/* check res without width later! */

int		print_percent_conversion()
{
	char	*width;
	int		width_len;

	width = set_width(0);
	width_len = ft_strlen(width);
	if (width_len > 1)
	{
		if (g_head->flag_minus == 1)
			width[0] = '%';
		else
			width[width_len - 1] = '%';
		ft_putstr(width);
	}
	else
		ft_putchar('%');
	return ((width_len >= 1) ? width_len : 1);
}
