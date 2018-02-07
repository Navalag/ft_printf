/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:02:25 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/11 11:02:28 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <locale.h>
// #include <wchar.h>
#include "ft_printf.h"

int		main(void)
{
	setlocale(LC_ALL, "");
	// wchar_t *value = L"ЇЇЇ";
	// wchar_t *value2 = L"我是一只猫。";
	// wchar_t value3 = L'我';
	int		ret_1;
	int		ret_2;
	// fflush(stdout);
	// char *str = L"我是一只猫";
	ret_1 = ft_printf("Bla Bla %i\n", 12);
	   ret_2 = printf("Bla Bla %i\n", 123);

	printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);
	   // printf("Bla Bla %#05x\n", 123);
	

	// printf("%####-----++++S %##s \n", 12);

	return (0);
}
