/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:54:13 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/13 10:18:36 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	*blank_input(void)
{
	char	*s;

	if (!(s = (char *)malloc(1)))
		return (0);
	s[0] = '\0';
	return (s);
}

static	int		ft_is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*res;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (*s && ft_is_white_space(s[i]))
		i++;
	if (i == len)
		return (blank_input());
	while (i < len && ft_is_white_space(s[len - 1]))
		len--;
	res = ft_strnew(len - i);
	if (res == NULL)
		return (NULL);
	j = 0;
	while (i < len)
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}
