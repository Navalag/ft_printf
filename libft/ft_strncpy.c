/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:47:32 by agalavan          #+#    #+#             */
/*   Updated: 2017/10/31 13:47:35 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *origin;

	origin = dst;
	while (len-- != 0)
	{
		if (*src != '\0')
			*dst++ = *src++;
		else
			*dst++ = '\0';
	}
	return (origin);
}
