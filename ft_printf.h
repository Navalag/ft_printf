/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:04:54 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/11 11:04:56 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_fl
{
	unsigned		flag_hesh:1;
	unsigned		flag_minus:1;
	unsigned		flag_plus:1;
	unsigned		flag_zero:1;
	unsigned		flag_space:1;
	int				width;
	int				precision;
	unsigned		size_hh:1;
	unsigned		size_h:1;
	unsigned		size_ll:1;
	unsigned		size_l:1;
	unsigned		size_j:1;
	unsigned		size_z:1;

	unsigned		conv_s:1;
	unsigned		conv_S:1;
	unsigned		conv_p:1;
	unsigned		conv_D:1;
	unsigned		conv_d:1;
	unsigned		conv_i:1;
	unsigned		conv_o:1;
	unsigned		conv_O:1;
	unsigned		conv_u:1;
	unsigned		conv_U:1;
	unsigned		conv_x:1;
	unsigned		conv_X:1;
	unsigned		conv_c:1;
	unsigned		conv_C:1;
}				t_flags;

t_flags		*g_head;

// typedef struct	s_all_flags
// {
// 	char	*all_flags = "#0-+ ";
// 	char	*all_sizes = "hljz";
// 	char	*all_conversions = "sSpdDioOuUxXcC%";
// }				t_all_flags;

void		ft_printf(char *fmt, ...);
int			validate_format(char *frm);
void		begin_validation(char *frm);
void		continue_with_width(char *frm);
void		read_flags_from_format(char *frm);
char		*ft_strchr(const char *s, int c);
void		continue_with_precision(char *frm);
void		continue_with_size(char *frm);

#endif
