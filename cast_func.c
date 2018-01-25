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

char	*cast_d_i_size(va_list ap)
{
	/* check itoa to work with more than int */
	if (g_head->size_hh == 1)
		return (itoa_base_sign((signed char)va_arg(ap, int)));
	else if (g_head->size_h == 1)
		return (itoa_base_sign((short)va_arg(ap, int)));
	else if (g_head->size_ll == 1)
		return (itoa_base_sign(va_arg(ap, long long int)));
	else if (g_head->size_l == 1)
		return (itoa_base_sign(va_arg(ap, long int)));
	else if (g_head->size_j == 1)
		return (itoa_base_sign(va_arg(ap, intmax_t)));
	else if (g_head->size_z == 1)
		return (itoa_base_sign(va_arg(ap, size_t))); // check if z with int values
	else
		return (itoa_base_sign(va_arg(ap, int)));
}

char	*cast_u_U_o_O_x_X_size(va_list ap, int base, int up_case)
{
	/* check itoa to work with more than int */
	if (g_head->size_z == 1)
		return (itoa_base_unsign(va_arg(ap, size_t), base, up_case));
	else if (g_head->size_j == 1)
		return (itoa_base_unsign(va_arg(ap, intmax_t), base, up_case));
	else if (g_head->size_ll == 1)
		return (itoa_base_unsign(va_arg(ap, unsigned long long int), base, up_case));
	else if (g_head->size_l == 1)
		return (itoa_base_unsign(va_arg(ap, unsigned long int), base, up_case));
	else if (g_head->size_h == 1)
		return (itoa_base_unsign((unsigned short)va_arg(ap, int), base, up_case));
	else if (g_head->size_hh == 1)
		return (itoa_base_unsign((unsigned char)va_arg(ap, int), base, up_case));
	else
		return (itoa_base_unsign(va_arg(ap, unsigned int), base, up_case));
}

char	*cast_s_size(va_list ap)
{
	return (va_arg(ap, char *));
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
