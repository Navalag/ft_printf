/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 08:35:34 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/02 08:35:37 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include "libft/libft.h"
#include "ft_printf.h"

char	*set_flag_for_d_i_u(char *res)
{
	if (g_head->flag_plus == 1)
		res = set_plus_flag(res);
	else if (g_head->flag_space == 1)
		res = set_space_flag(res);
	if (g_head->width > 0)
	{
		if (g_head->flag_minus == 1)
			res = set_minus_flag(res);
		else if (g_head->flag_zero == 1 && g_head->precision_flag == 0)
			res = set_zero_flag(res);
	}
	return (res);
}

char	*set_flag_for_o_x_X(char *res)
{
	if (g_head->width > 0)
	{
		if (g_head->flag_minus == 1)
			res = set_minus_flag(res);
		else if (g_head->flag_zero == 1 && g_head->precision_flag == 0)
			res = set_zero_flag(res);
	}
	if (g_head->flag_hesh == 1)// && g_head->conver_letter == 'o') // check conver_letter
	{

		res = set_hesh_flag_for_octal(res);
	}
	// else if (g_head->flag_hesh == 1 && g_head->conver_letter == 'x')
	// 	res = set_hesh_flag_for_hexadecimal(res);
	return (res);
}

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

// char	*set_hesh_flag_for_hexadecimal(char *res)
// {
// 	int		i;
// 	char	*tmp;

// 	i = 0;
// 	while (res[i] == ' ')
// 		i++;
// 	if (i >= 2)
// 	{
// 		if (g_head->conver_letter == 'x')
// 			res[i - 1] = 'x';
// 		else if (g_head->conver_letter == 'X')
// 			res[i] = 'X';
// 		res[i - 2] = '0';
// 	}
// 	else if (res[i] == '0' && res[i + 1] == '0' && g_head->flag_zero == 1)
// 	{
// 		if (g_head->conver_letter == 'x')
// 			res[i - 1] = 'x';
// 		else if (g_head->conver_letter == 'X')
// 			res[i] = 'X';
// 		res[i - 2] = '0';
// 	}
// 	else
// 	{

// 	}
// }

/* check if value can be with "+" sign */

char	*set_plus_flag(char *res)
{
	int		i;
	char	*tmp;

	i = 0;
	while (res[i] == ' ')
		i++;
	if (res[i] == '-')
		return (res);
	else if (res[i] != '-' && i != 0)
		res[i - 1] = '+';
	else
	{
		tmp = ft_strjoin("+", res);
		free(res);
		res = tmp;
	}
	return (res);
}

char	*set_space_flag(char *res)
{
	int		i;
	char	*tmp;

	i = 0;
	while (res[i] == ' ')
		i++;
	if (res[i] == '-')
		return (res);
	else if (res[i] != '-' && i != 0)
		res[i - 1] = ' ';
	else
	{
		tmp = ft_strjoin(" ", res);
		free(res);
		res = tmp;
	}
	return (res);
}

char	*set_minus_flag(char *res)
{
	int		i;

	i = 0;
	while (res[i] == ' ')
		i++;
	if (g_head->flag_space == 1 && res[i] != '-' && res[i] != '+')
		i--;
	res = ft_memmove(res, res + i, ft_strlen(res) - i);
	ft_memset(res + (ft_strlen(res) - i), ' ', i);
	return (res);
}

/* fix cases with '+' '-' sign */

char	*set_zero_flag(char *res)
{
	int		i;
	char	*tmp;

	i = 0;
	if (res[i] != ' ')
		return (res);
	else if ((tmp = ft_strchr(res, '-')) == NULL && g_head->flag_space == 1 &&
			g_head->flag_plus == 0)
		i++;
	else if ((tmp = ft_strchr(res, '-')) != NULL)
	{
		*tmp = '0';
		res[0] = '-';
		i++;
	}
	else if ((tmp = ft_strchr(res, '+')) != NULL)
	{
		*tmp = '0';
		res[0] = '+';
		i++;
	}
	while (res[i] == ' ')
		res[i++] = '0';
	return (res);
}

// int		main(void)
// {
// 	char	width[] = "      00000";
// 	char	value[] = "-1234";
// 	int		width_len = ft_strlen(width);
// 	int		value_len = ft_strlen(value);
// 	char	*res;

// 	res = NULL;
// 	res = set_space_flag(width, value, res, width_len, value_len);
// 	printf("%s\n", res);
// 	res = set_minus_flag(width, value, res, width_len, value_len);
// 	printf("%s\n", res);
// 	return (0);
// }
