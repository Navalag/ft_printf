/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 10:16:36 by agalavan          #+#    #+#             */
/*   Updated: 2017/10/31 10:16:39 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*res;

	len = 0;
	i = 0;
	while (s1[len] != '\0')
		len++;
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
