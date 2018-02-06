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

void	begin_process(va_list ap, char *frm)
{
	int		count;
	int		ret_value;

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
			count = read_flags_from_format(frm, ap);
			frm += count;
			ret_value = continue_with_conversions(frm, ap, count);
			frm++;
			// printf("%s\n", frm);
		}
	}
}

void	ft_printf(char *format, ...)
{
	va_list		ap;
	char		*p;

	va_start(ap, format);
	p = format;
	begin_process(ap, p);

	va_end(ap);
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
