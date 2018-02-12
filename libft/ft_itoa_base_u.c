/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_itoa_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:57:23 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/12 10:57:25 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_base_u(size_t nb, int base, int up_case)
{
	char	*res;
	int		len;
	char	*symb_lower;
	char	*symb_upper;

	len = ft_intlen_u(nb, base);
	symb_lower = "0123456789abcdef";
	symb_upper = "0123456789ABCDEF";
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		res[len] = (up_case) ? symb_upper[nb % base] : symb_lower[nb % base];
		nb /= base;
	}
	return (res);
}
