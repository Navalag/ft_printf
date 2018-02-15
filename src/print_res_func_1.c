/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res_func_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:45:15 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/14 10:45:17 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		print_s_conversion(va_list ap)
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
	clean_memory_leaks(res);
	return (res_len);
}

int		print_S_conversion(va_list ap)
{
	char			*width;
	wchar_t			*value;
	int				res_len;

	width = set_width(0);
	value = cast_S_size(ap);
	if (value == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	res_len = generate_and_print_utf_str(width, value);
	clean_memory_leaks(width);
	return (res_len);
}

int		print_c_conversion(va_list ap)
{
	char	*width;
	char	value;
	int		width_len;
	int		res_len;

	width = set_width(0);
	if (g_head->conver_letter == 'c')
		value = cast_c_size(ap);
	else
		value = g_head->conver_letter;
	width_len = ft_strlen(width);
	res_len = set_flag_for_c(width, value, width_len, 0);
	clean_memory_leaks(width);
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
	clean_memory_leaks(width);
	return (res_len);
}