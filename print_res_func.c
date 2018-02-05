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

wchar_t	*ft_utf_strcpy(wchar_t *dst, const wchar_t *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

wchar_t	*ft_utf_strncpy(wchar_t *dst, const wchar_t *src, size_t len)
{
	while (len-- > 0)
	{
		if (*src)
		{
			*dst = *src;
			dst++;
			src++;
		}
		else
		{
			*dst = 0;
			dst++;
		}
	}
	printf("%S\n", dst);
	return (dst);
}

wchar_t	*generate_res_for_utf(wchar_t *width, wchar_t *value)
{
	wchar_t	*res;
	int				width_len;
	int				value_len;
	int				i;

	width_len = ft_utf_strlen(width);
	printf("%i\n", width_len);
	value_len = ft_utf_strlen(value);
	printf("%i\n", value_len);
	i = 0;
	if (width_len <= value_len)
	{
		if (g_head->precision >= value_len)
			res = value;
		else
			res = ft_utf_strncpy(value, value, g_head->precision);
	}
	else
	{
		while (width_len > value_len || width_len > g_head->precision)
		{
			i++;
			width_len--;
		}
		if (g_head->precision_flag == 1)
			ft_utf_strncpy(width + i, value, g_head->precision);
		else
			ft_utf_strcpy(width + i, value);
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
	res = set_flag_for_d_i_u(generate_res_for_int(width, value));
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
	res = set_flag_for_o_x_X(generate_res_for_int(width, value));
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
	res = set_flag_for_s(generate_res_for_str(width, value));
	res_len = ft_strlen(res);
	ft_putstr(res);
}

void	print_S_conversion(va_list ap)
{
	char			*width;
	wchar_t			*value;
	wchar_t			*res;
	int				res_len;

	width = set_width(0);
	value = cast_S_size(ap);
	res = set_flag_for_utf(generate_res_for_utf((wchar_t *)width, (wchar_t *)value));
	res_len = ft_strlen((char *) res);
	// printf("%S\n", (wchar_t *)res);
	// while ((char)*res == ' ' || (char)*res == '0')
	// {
	// 	ft_putchar((char)*res);
	// 	res++;
	// }
	// printf("%S\n", (wchar_t *)res);
	while (*res)
	{
		print_unicode((unsigned int)*res);
		res++;
	}
	// if (width_len <= value_len)
	// {
	// 	free(width);
	// 	while (*value)
	// 	{
	// 		print_unicode((unsigned int)*value);
	// 		value++;
	// 	}
	// }
	// else
	// {
	// 	while (width_len > value_len)
	// 	{
	// 		ft_putchar(*width);
	// 		width++;
	// 		width_len--;
	// 	}
	// 	while (*value)
	// 	{
	// 		print_unicode((unsigned int)*value);
	// 		value++;
	// 	}
	// }
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
