/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 10:33:59 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/03 10:34:02 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_copy;

	b_copy = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b_copy[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
