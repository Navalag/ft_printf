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
** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx		0000000000000000 0110 001000 010001 - 25105
**											000000000000000000000 10000  000111 - 1031
*/

// #include "ft_printh.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>

int		find_bin_size(unsigned int val)
{
	int				count;

	count = 1;
	while (val >>= 1)
		count++;
	return (count);
}

void	continue_with_2_bytes(unsigned int S_val)
{
	unsigned char	o2;
	unsigned char	o1;
	unsigned char	octet;
	unsigned int 	mask; // check and fix it later

	mask = 49280;
	o2 = (S_val << 26) >> 26; // 7
	o1 = ((S_val >> 6) << 27) >> 27; // 16
	octet = (mask >> 8) | o1;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o2;
	write(1, &octet, 1);
}

void	continue_with_3_bytes(unsigned int S_val)
{
	unsigned char	o3;
	unsigned char	o2;
	unsigned char	o1;
	unsigned char	octet;
	unsigned int 	mask; // check and fix it later

	mask = 14712960;
	o3 = (S_val << 26) >> 26; // 17
	o2 = ((S_val >> 6) << 26) >> 26; // 8
	o1 = ((S_val >> 12) << 28) >> 28; // 6
	octet = (mask >> 16) | o1;
	write(1, &octet, 1);
	octet = ((mask << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o3;
	write(1, &octet, 1);
}

void	continue_with_4_bytes(unsigned int S_val)
{
	unsigned char	o4;
	unsigned char	o3;
	unsigned char	o2;
	unsigned char	o1;
	unsigned char	octet;
	unsigned int 	mask; // check and fix it later

	mask = 4034953344;
	o4 = (S_val << 26) >> 26;
	o3 = ((S_val >> 6) << 26) >> 26;
	o2 = ((S_val >> 12) << 26) >> 26;
	o1 = ((S_val >> 18) << 29) >> 29;
	octet = (mask >> 24) | o1;
	write(1, &octet, 1);
	octet = ((mask << 8) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask << 16) >> 24) | o3;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o4;
	write(1, &octet, 1);
}

void	print_unicode(unsigned int S_val)
{
	int		size;
	// setlocale(LC_ALL, "en_US.UTF-8");
	// int		i;

	// while (S_val[i] != 0)
	// {
		size = find_bin_size(S_val);
		if (size <= 7)
			write(1, &S_val, 1);
		else if (size <= 11)
			continue_with_2_bytes(S_val);
		else if (size <= 16)
			continue_with_3_bytes(S_val);
		else
			continue_with_4_bytes(S_val);
		// i++;
	// }
}

// void	print_bits_2(unsigned int octet)
// {
// 	size_t	i;

// 	i = 4294967296;
// 	while (i >>= 1)
// 		(octet & i) ? write(1, "1", 1) : write(1, "0", 1);
// }

// int		main(void)
// {
// 	setlocale(LC_ALL, "en_US.UTF-8");
// 	// printf("%i\n", find_bin_size(100));
// 	wchar_t *value = L"ЇїЇ абабагаламага";
// 	wchar_t *value2 = L"我是一只猫。";
// 	// print_bits_2(value);
// 	print_unicode((unsigned int *)value2);
// 	return (0);
// }
