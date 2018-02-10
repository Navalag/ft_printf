/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 10:28:25 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/23 10:28:28 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*cast_D_d_i_size(va_list ap)
{
	if (g_head->conver_letter == 'D')
		return (s_itoa_base(va_arg(ap, long int)));
	else if (g_head->size_z == 1)
		return (s_itoa_base(va_arg(ap, intmax_t)));
	else if (g_head->size_j == 1)
		return (s_itoa_base(va_arg(ap, intmax_t)));
	else if (g_head->size_ll == 1)
		return (s_itoa_base(va_arg(ap, intmax_t)));
	else if (g_head->size_l == 1)
		return (s_itoa_base(va_arg(ap, long int)));
	else if (g_head->size_hh == 1)
		return (s_itoa_base((signed char)va_arg(ap, int)));
	else if (g_head->size_h == 1)
		return (s_itoa_base((short)va_arg(ap, int)));
	else
		return (s_itoa_base(va_arg(ap, int)));
}

char	*cast_u_U_o_O_x_X_size(va_list ap, int base, int up_case)
{
	if (g_head->conver_letter == 'U')
		return (u_itoa_base(va_arg(ap, unsigned long), base, up_case));
	else if (g_head->conver_letter == 'O')
		return (u_itoa_base(va_arg(ap, unsigned long), base, up_case));
	else if (g_head->conver_letter == 'p')
		return (u_itoa_base(va_arg(ap, size_t), base, up_case));
	else if (g_head->size_z == 1)
		return (u_itoa_base(va_arg(ap, size_t), base, up_case));
	else if (g_head->size_j == 1)
		return (u_itoa_base(va_arg(ap, uintmax_t), base, up_case));
	else if (g_head->size_ll == 1)
		return (u_itoa_base(va_arg(ap, uintmax_t), base, up_case));
	else if (g_head->size_l == 1)
		return (u_itoa_base(va_arg(ap, unsigned long), base, up_case));
	else if (g_head->size_hh == 1)
		return (u_itoa_base((unsigned char)va_arg(ap, int), base, up_case));
	else if (g_head->size_h == 1)
		return (u_itoa_base((unsigned short)va_arg(ap, int), base, up_case));
	else
		return (u_itoa_base(va_arg(ap, unsigned int), base, up_case));
}

char	*cast_s_size(va_list ap)
{
	char	*res;

	res = va_arg(ap, char *);
	if (res == NULL)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(res);
	return (res);
}

wchar_t	*cast_S_size(va_list ap)
{
	return (va_arg(ap, wchar_t *));
}

char	cast_c_size(va_list ap)
{
	return ((unsigned char)va_arg(ap, int));
}

wchar_t	cast_C_size(va_list ap)
{
	return (va_arg(ap, wchar_t));
}
