/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:04:05 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/11 11:04:07 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int		begin_process(va_list ap, char *frm)
// {
// 	int		count;
// 	int		ret_value;

// 	ret_value = 0;
// 	begin_validation(frm);
// 	while (*frm)
// 	{
// 		if (*frm != '%')
// 		{
// 			ft_putchar(*frm);
// 			frm++;
// 			ret_value++;
// 		}
// 		else
// 		{
// 			frm++;
// 			// ret_value++;
// 			count = read_flags_from_format(frm);
// 			frm += count;
// 			ret_value += continue_with_conversions(frm++, ap);
// 			// frm++;
// 			// printf("%i\n", ret_value);
// 		}
// 	}
// 	return (ret_value);
// }

int		ft_printf(char *frm, ...)
{
	va_list		ap;
	int			ret_value;
	int			count;

	va_start(ap, frm);
	ret_value = 0;
	begin_validation(frm);
	while (*frm)
	{
		if (*frm != '%')
		{
			ft_putchar(*frm);
			frm++;
			ret_value++;
		}
		else
		{
			frm++;
			// ret_value++;
			count = read_flags_from_format(frm);
			frm += count;
			ret_value += continue_with_conversions(frm++, ap);
			// frm++;
			// printf("%i\n", ret_value);
		}
	}
	va_end(ap);
	return (ret_value);
}

// void	begin_process(va_list ap, char *frm)
// {
// 	int			count;

// 	begin_validation(frm);
// 	while (*frm)
// 	{
// 		if (*frm != '%')
// 		{
// 			ft_putchar(*frm);
// 			frm++;
// 		}
// 		else
// 		{
// 			frm++;
// 			count = read_flags_from_format(frm, ap);
// 			frm += count;
// 		}
// 	}
// }

// void	ft_printf(char *format, ...)
// {
// 	va_list		ap;
// 	int			count;
// 	int			ret_value;

// 	ret_value = 0;
// 	va_start(ap, format);
// 	begin_validation(format);
// 	while (*format)
// 	{
// 		if (*format != '%')
// 		{
// 			ft_putchar(*format);
// 			format++;
// 			ret_value++;
// 		}
// 		else
// 		{
// 			format++;
// 			count = read_flags_from_format(format);
// 			format += count;
// 			ret_value += continue_with_conversions(format, ap);
// 			printf("%i\n", ret_value);
// 		}
// 	}
// 	va_end(ap);
// }
