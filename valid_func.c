/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:18:31 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/11 16:18:35 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int		begin_validation(char *frm)
// {
// 	int		count;

// 	// if (frm == NULL || ap == NULL)
// 	// 	exit (0);
// 	while (*frm)
// 	{
// 		if (*frm != '%')
// 			frm++;
// 		else
// 		{
// 			frm++;
// 			if ((count = validate_format(frm)) == 0)
// 				exit (0);
// 			frm += count;
// 		}
// 	}
// }

/* can be optimized without validation later */

int		validate_format(char *frm)
{
	char	*all_flags;
	char	*all_sizes;
	char	*all_conversions;
	int		i;

	all_flags = "#0-+ ";
	all_sizes = "hljz";
	all_conversions = "sSpdDioOuUxXcC%";
	i = 0;
	while (ft_strchr(all_flags, frm[i]) != 0)
		i++;
	while (frm[i] >= '0' && frm[i] <= '9')
		i++;
	if (frm[i] == '.')
		i++;
	while (frm[i] >= '0' && frm[i] <= '9')
		i++;
	while (ft_strchr(all_sizes, frm[i]) != 0) // check size format (hh - ok, hhh )
		i++;
	if (ft_strchr(all_conversions, frm[i]) != 0)
		return (++i);
	return (0);
}
