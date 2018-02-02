#include <stdio.h>
#include "libft/libft.h"
// #include "ft_printf.h"

char	*set_flag_for_d_i_u(char *width, char *value)
{
	int		width_len;
	int		value_len;
	char	*res;

	width_len = ft_strlen(width);
	value_len = ft_strlen(value);
	res = NULL;
	if (g_head->flag_plus == 1)
		res = set_plus_flag(width, value, res, width_len, value_len);
	else if (g_head->flag_space == 1)
		res = set_space_flag(width, value, res, width_len, value_len);
	if (g_head->width > value_len)
	{
		if (g_head->flag_minus == 1)
			res = set_minus_flag(width, value, res);
		else if (g_head->flag_zero == 1 && g_head->precision_flag == 0)
			res = set_plus_flag(width, value, res);
	}
	return (res);
}

/* check if value can be with "+" sign */

char	*set_plus_flag(char *width, char *value, char *res,
						int width_len, int value_len)
{
	int		i;

	i = 0;
	if (width_len <= value_len)
		if (value[0] == '-')
			res = value;
		else
			res = ft_strjoin("+", value);
	else
	{
		while (value_len && value[value_len - 1] != '-')
			width[--width_len] = value[--value_len];
		while (width[i] && width[i] == ' ' && width[i + 1] == ' ')
			i++;
		if (width[i] == ' ' && width[i + 1] != ' ')
		{
			if (value[0] == '-')
				width[i] = '-';
			else
				width[i] = '+';
			res = width;
		}
		else if (value[0] == '-')
			res = ft_strjoin("-", width);
		else
			res = ft_strjoin("+", width);
	}
	return (res);
}

char	*set_space_flag(char *width, char *value, char *res,
						int width_len, int value_len)
{
	int		i;

	i = 0;
	if (width_len <= value_len)
		if (value[0] == '-')
			res = value;
		else
			res = ft_strjoin(" ", value);
	else
	{
		while (value_len && value[value_len - 1] != '-')
			width[--width_len] = value[--value_len];
		while (width[i] && width[i] == ' ' && width[i + 1] == ' ')
			i++;
		if (width[i] == ' ' && width[i + 1] != ' ')
		{
			if (value[0] == '-')
				width[i] = '-';
			else
				width[i] = ' ';
			res = width;
		}
		else if (value[0] == '-')
			res = ft_strjoin("-", width);
		else
			res = ft_strjoin(" ", width);
	}
	return (res);
}

char	*set_minus_flag(char *width, char *value, char *res,
						int width_len, int value_len)
{
	int		i;

	i = 0;
	if (res != NULL)
	{
		while (res[i] == ' ')
			i++;
		// if (g_head->flag_space == 1)
			// i--;
		res = ft_memmove(res, res + i, ft_strlen(res) - i);
		ft_memset(res + (ft_strlen(res) - i), ' ', i);
	}
	else
	{
		i = 0;
		while (value_len && value[value_len - 1] != '-')
			width[--width_len] = value[--value_len];
		while (res[i] == ' ')
			i++;
		// if (g_head->flag_space == 1)
			// i--;
		res = ft_memmove(res, res + i, ft_strlen(res) - i);
		ft_memset(res + (ft_strlen(res) - i), ' ', i);
	}
	return (res);
}

int		main(void)
{
	char	width[] = "      00000";
	char	value[] = "-1234";
	int		width_len = ft_strlen(width);
	int		value_len = ft_strlen(value);
	char	*res;

	res = NULL;
	res = set_space_flag(width, value, res, width_len, value_len);
	printf("%s\n", res);
	res = set_minus_flag(width, value, res, width_len, value_len);
	printf("%s\n", res);
	return (0);
}
