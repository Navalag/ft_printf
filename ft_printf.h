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
# include "libft/libft.h"

typedef struct	s_fl
{
	unsigned	flag_hesh:1;
	unsigned	flag_minus:1;
	unsigned	flag_plus:1;
	unsigned	flag_zero:1;
	unsigned	flag_space:1;
	int			width;
	int			precision;
	unsigned	size_hh:1;
	unsigned	size_h:1;
	unsigned	size_ll:1;
	unsigned	size_l:1;
	unsigned	size_j:1;
	unsigned	size_z:1;
}				t_flags;

t_flags		*g_head;

void		ft_printf(char *fmt, ...);

int			validate_format(char *frm);
void		begin_validation(char *frm);

void		clean_flags_struct();
int			read_flags_from_format(char *frm, va_list ap);
int			continue_with_width(char *frm, va_list ap, int count);
int			continue_with_precision(char *frm, va_list ap, int count);
int			continue_with_size(char *frm, va_list ap, int count);
int			continue_with_conversions(char *frm, va_list ap, int count);

void		print_d_i_conversions(va_list ap);
void		print_u_U_o_O_x_X_conversion(va_list ap, int base, int up_case);
void		print_percent_conversion();

char		*set_precision(char *res);
char		*set_width(int prec_y_n);

char		*cast_d_i_size(va_list ap);
char		*cast_u_U_o_O_x_X_size(va_list ap, int base, int up_case);

char		*itoa_base_unsign(size_t nb, int base, int upper_case);
char		*itoa_base_sign(long long int nb);

#endif
