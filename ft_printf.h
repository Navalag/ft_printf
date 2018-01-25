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
# include <wchar.h>
# include <locale.h>
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
	unsigned	precision_flag:1;
	unsigned	size_hh:1;
	unsigned	size_h:1;
	unsigned	size_ll:1;
	unsigned	size_l:1;
	unsigned	size_j:1;
	unsigned	size_z:1;
	char		conver_letter:1;
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
void		print_s_conversion(va_list ap);
void		print_s_continue(char *s_val, char *res);
void		print_S_conversion(va_list ap);
void		print_c_conversion(va_list ap);
void		print_C_conversion(va_list ap);
void		print_percent_conversion();

char		*set_int_precision(char *res);
char		*set_width(int prec_y_n);

char		*cast_d_i_size(va_list ap);
char		*cast_u_U_o_O_x_X_size(va_list ap, int base, int up_case);
char		*cast_s_size(va_list ap);
wchar_t		*cast_S_size(va_list ap);
char		cast_c_size(va_list ap);
wchar_t		cast_C_size(va_list ap);

char		*itoa_base_unsign(size_t nb, int base, int upper_case);
char		*itoa_base_sign(long long int nb);
int			ft_intlen(size_t nb, int base);

int			find_bin_size(unsigned int val);
void		continue_with_2_bytes(unsigned int S_val);
void		continue_with_3_bytes(unsigned int S_val);
void		continue_with_4_bytes(unsigned int S_val);
void		print_unicode(unsigned int S_val);

#endif
