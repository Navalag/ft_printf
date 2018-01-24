/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicod_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:24:20 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/24 13:24:23 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 0xxxxxxx
** 110xxxxx 10xxxxxx
** 1110xxxx 10xxxxxx 10xxxxxx
** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

// #include "ft_printh.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>

int		find_bin_size(unsigned int val)
{
	unsigned int	j;
	int				count;

	val = val & 121585471;  //  0000 0111  0011 1111  0011 1111  0011 1111
	j = 134217728;  //  0000 1000  0000 0000  0000 0000  0000 0000
	count = 21;
	while (j >>= 1)
	{
		if (j & val)
			return (count);
		if (j & 121585471)
			count--;
	}
	return (0);
}

void	continue_with_2_bytes(wchar_t *S_val)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	octet;
	unsigned int 	mask; // check and fix it later

	mask = 49280;
	o1 = (*S_val << 26) >> 26;
	o2 = ((*S_val >> 6) << 26) >> 27;
	octet = (mask >> 8) | o2;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o1;
	write(1, &octet, 1);
}

void	continue_with_3_bytes(wchar_t *S_val)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	octet;
	unsigned int 	mask; // check and fix it later

	mask = 14712960;
	o1 = (*S_val << 26) >> 26;
	o2 = ((*S_val >> 6) << 26) >> 26;
	o3 = ((*S_val >> 12) << 28) >> 28;
	octet = (mask >> 16) | o3;
	write(1, &octet, 1);
	octet = ((mask << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o1;
	write(1, &octet, 1);
}

void	continue_with_4_bytes(wchar_t *S_val)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;
	unsigned char	octet;
	unsigned int 	mask; // check and fix it later

	mask = 4034953344;
	o1 = (*S_val << 26) >> 26;
	o2 = ((*S_val >> 6) << 26) >> 26;
	o3 = ((*S_val >> 12) << 26) >> 26;
	o4 = ((*S_val >> 18) << 29) >> 29;
	octet = (mask >> 24) | o4;
	write(1, &octet, 1);
	octet = ((mask << 8) >> 24) | o3;
	write(1, &octet, 1);
	octet = ((mask << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o1;
	write(1, &octet, 1);
}

void	print_unicode(wchar_t *S_val)
{
	int		size;


	while (*S_val)
	{
		size = find_bin_size(*S_val);
		if (size <= 7)
			write(1, &S_val, 1);
		else if (size <= 11)
			continue_with_2_bytes(S_val);
		else if (size <= 16)
			continue_with_3_bytes(S_val);
		else
			continue_with_4_bytes(S_val);
		S_val++;
	}
}

int		main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	// printf("%i\n", find_bin_size(187179572));
	print_unicode(L'ЇЇЇ');
	return (0);
}
