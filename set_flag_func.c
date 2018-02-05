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
		{
			res = set_minus_flag(res);
			g_head->flag_zero = 0;
		}
		else if (g_head->flag_zero == 1 && g_head->precision_flag == 0)
			res = set_zero_flag(res);
		else
			g_head->flag_zero = 0;
	}
	return (res);
}

char	*set_flag_for_o_x_X(char *res)
{
	if (g_head->flag_minus == 1 || g_head->precision_flag == 1)
		g_head->flag_zero = 0;
	if (g_head->flag_hesh == 1 && g_head->conver_letter == 'o') // check conver_letter
		res = set_hesh_flag_for_octal(res);
	else if (g_head->flag_hesh == 1 && g_head->conver_letter == 'x')
		res = set_hesh_flag_for_hexadecimal_x(res);
	else if (g_head->flag_hesh == 1 && g_head->conver_letter == 'X')
		res = set_hesh_flag_for_hexadecimal_X(res);
	if (g_head->width > 0)
	{
		if (g_head->flag_minus == 1)
			res = set_minus_flag(res);
		else if (g_head->flag_zero == 1)
			res = set_zero_flag(res);
	}
	return (res);
}

char	*set_flag_for_s(char *res)
{
	/* necessary for this implemenation (see set_minus_flag function) */
	g_head->flag_space = 0;
	if (g_head->width > 0)
	{
		if (g_head->flag_minus == 1)
			res = set_minus_flag(res);
		else if (g_head->flag_zero == 1)
			res = set_zero_flag_for_s(res);
	}
	return (res);
}

wchar_t	*set_flag_for_utf(wchar_t *res)
{
	/* necessary for this implemenation (see set_minus_flag function) */
	g_head->flag_space = 0;
	if (g_head->width > 0)
	{
		if (g_head->flag_minus == 1)
			res = (wchar_t *)set_minus_flag((char *)res);
		else if (g_head->flag_zero == 1)
			res = (wchar_t *)set_zero_flag_for_s((char *)res);
	}
	return (res);
}

int		set_flag_for_c(char *width, char value, int width_len, int i)
{
	if (width_len <= 1)
	{
		ft_putchar(value);
		return (1);
	}
	else
	{
		if (g_head->flag_minus == 1)
		{
			ft_putchar(value);
			ft_putstr(width + 1);
		}
		else if (g_head->flag_zero == 1)
		{
			while (width_len - 1 > i++)
				ft_putchar('0');
			ft_putchar(value);
		}
		else
		{
			ft_putstr(width + 1);
			ft_putchar(value);
		}
	}
	return (width_len);
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
	else if ((tmp = ft_strchr(res, '-')) != NULL ||
			(tmp = ft_strchr(res, '+')) != NULL)
	{
		res[0] = (*tmp == '-') ? '-' : '+';
		*tmp = '0';
		i++;
	}
	while (res[i] == ' ')
		res[i++] = '0';
	return (res);
}

char	*set_zero_flag_for_s(char *res)
{
	int		i;
	char	*tmp;

	i = 0;
	if (res[i] != ' ')
		return (res);
	while (res[i] == ' ')
		res[i++] = '0';
	return (res);
}
