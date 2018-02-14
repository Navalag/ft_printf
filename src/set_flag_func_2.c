/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag_func2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:02:27 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/14 11:02:30 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*set_hesh_flag_for_octal(char *res)
{
	int		i;
	char	*tmp;

	i = 0;
	while (res[i] == ' ')
		i++;
	if (res[i] == '0')
		return (res);
	else if (i != 0)
		res[i - 1] = '0';
	else
	{
		tmp = ft_strjoin("0", res);
		free(res);
		res = tmp;
	}
	return (res);
}

char	*set_hesh_flag_for_hexadecimal_x(char *res)
{
	int		i;
	char	*tmp;

	i = 0;
	while (res[i] == ' ' || (g_head->flag_zero == 1 && res[i] == '0'))
		i++;
	if (i >= 2)
	{
		while (res[i - 1] == '0' && i > 0)
			i--;
		/* this condition works for 'space' cases. When we put 0x close
		   to the number. */
		if (i >= 2)
		{
			res[i - 1] = 'x';
			res[i - 2] = '0';
		}
		/* this condition works for 'zero' cases. Before it
		   while loop would always return 'i' at the beginning of the string */
		else
		{
			res[i + 1] = 'x';
			res[i] = '0';
		}
	}
	else if (i == 1)
	{
		res[0] = 'x';
		tmp = ft_strjoin("0", res);
		free(res);
		res = tmp;
	}
	else
	{
		tmp = ft_strjoin("0x", res);
		free(res);
		res = tmp;
	}
	return (res);
}

char	*set_hesh_flag_for_hexadecimal_X(char *res)
{
	int		i;
	char	*tmp;

	i = 0;
	while (res[i] == ' ' || (g_head->flag_zero == 1 && res[i] == '0'))
		i++;
	if (i >= 2)
	{
		while (res[i - 1] == '0' && i > 0)
			i--;
		if (i >= 1)
		{
			res[i - 1] = 'X';
			res[i - 2] = '0';
		}
		else
		{
			res[i + 1] = 'X';
			res[i] = '0';
		}
	}
	else if (i == 1)
	{
		res[0] = 'X';
		tmp = ft_strjoin("0", res);
		free(res);
		res = tmp;
	}
	else
	{
		tmp = ft_strjoin("0X", res);
		free(res);
		res = tmp;
	}
	return (res);
}
