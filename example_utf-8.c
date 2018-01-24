/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example_utf-8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:35:29 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/24 14:35:31 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 0xxxxxxx
** 110xxxxx 10xxxxxx
** 1110xxxx 10xxxxxx 10xxxxxx
** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

#include <locale.h>
#include <wchar.h>
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

int		main(int argc, char **argv)
{
	setlocale(LC_ALL, "en_US.UTF-8");

	wchar_t value = L'我';
	//我是一只猫。
	unsigned int mask0 = 0;
	unsigned int mask1 = 49280;
	unsigned int mask2= 14712960;
	unsigned int mask3= 4034953344;

	unsigned int v = value;
	int size = find_bin_size(value);
	int res = 0;
	printf("size %d\n", size);
	unsigned char octet;

    if (size <= 7)
    {
		octet = value;
		write(1, &octet, 1);
    }
    else  if (size <= 11)
    {
		unsigned char o2 = (v << 26) >> 26; // Восстановление первых 6 бит 110xxxxx 10(xxxxxx)
		unsigned char o1 = ((v >> 6) << 27) >> 27; // Восстановление последних 5 бит 110(xxxxx) 10xxxxxx

		octet = (mask1 >> 8) | o1; // Применение первой битовой маски ко первому байту
		write(1, &octet, 1);
		octet = ((mask1 << 24) >> 24) | o2; // Применение второй битовой маски ко второму байту
		write(1, &octet, 1);
    }
    else  if (size <= 16)
    {
		unsigned char o3 = (v << 26) >> 26; // Восстановление первых 6 бит 1110xxxx 10xxxxxx 10(xxxxxx)
		unsigned char o2 = ((v >> 6) << 26) >> 26; // Восстановление вторых 6 бит 1110xxxx 10(xxxxxx) 10xxxxxx
		unsigned char o1 = ((v >> 12) << 28) >> 28; // Восстановление последних 4 бит 1110(xxxx) 10xxxxxx 10xxxxxx

		octet = (mask2 >> 16) | o1; // Применение первой битовой маски ко первому байту
		write(1, &octet, 1);
		octet = ((mask2 << 16) >> 24) | o2; // Применение второй битовой маски ко второму байту
		write(1, &octet, 1);
		octet = ((mask2 << 24) >> 24) | o3; // Применение третьей битовой маски ко третьему байту
		write(1, &octet, 1);
    }
    else
    {
		unsigned char o4 = (v << 26) >> 26; // Восстановление первых 6 11110xxx 10xxxxxx 10xxxxxx 10(xxxxxx)
		unsigned char o3 = ((v >> 6) << 26) >> 26; // Восстановление вторых 6 бит 11110xxx 10xxxxxx 10(xxxxxx) 10xxxxxx
		unsigned char o2 = ((v >> 12) << 26) >> 26;  // Восстановление третьих 6 бит bits 11110xxx 10(xxxxxx) 10xxxxxx 10xxxxxx
		unsigned char o1 = ((v >> 18) << 29) >> 29; // Восстановление последних 3 бита 11110(xxx) 10xxxxxx 10xxxxxx 10xxxxxx

		octet = (mask3 >> 24) | o1; // Применение бит первого байта на первый байт маски
		write(1, &octet, 1);
		octet = ((mask3 << 8) >> 24) | o2; // Применение второй битовой маски ко второму байту
		write(1, &octet, 1);
		octet = ((mask3 << 16) >> 24) | o3; // Применение третьей битовой маски ко третьему байту
		write(1, &octet, 1);
		octet = ((mask3 << 24) >> 24) | o4; // Применение последней битовой маски ко последнему байту
		write(1, &octet, 1);
    }
    return (0);
}
