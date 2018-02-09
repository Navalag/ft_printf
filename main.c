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
	int 	*str;
	int		ret_1;
	int		ret_2;
	str = &ret_1;
	// fflush(stdout);
	// char *str = L"我是一只猫";
	// ret_1 = ft_printf("% Zoooo\n");
	   // ret_2 = printf("% Zoooo\n");

	// ret_1 = ft_printf("{%}\n");
	   // ret_2 = printf("{%}\n");

	// ft_printf("@moulitest: %.o %.0o\n", 0, 0);
	   // printf("@moulitest: %.o %.0o\n", 0, 0);

	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);
	   // printf("Bla Bla %#05x\n", 123);

	// ft_printf("%lc, %lc\n", L'暖', L'ح');
	//    printf("%lc, %lc\n", L'暖', L'ح');

	// ft_printf("%ls, %ls\n", L"暖炉", L"لحم خنزير");
	//    printf("%ls, %ls\n", L"暖炉", L"لحم خنزير");

	// ret_1 = ft_printf("{%10R}\n"); // test 50 - undefined behavior
	//    ret_2 = printf("{%10R}\n");
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("{%30S}\n", L"我是一只猫。");
	//    ret_2 = printf("{%30S}\n", L"我是一只猫。");
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("{%030S}\n", L"我是一只猫。");	// test 52 - undefined behavior
	//    ret_2 = printf("{%030S}\n", L"我是一只猫。");
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("{%030S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	//    ret_2 = printf("{%030S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("{%-15Z}\n", 123); // test 53 - undefined behavior
	//    ret_2 = printf("{%-15Z}\n", 123);
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("%#O\n", 1);
	//    ret_2 = printf("%#O\n", 1);
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("%.4S\n", L"我是一只猫。"); // test 72 - undefined behavior
	//    ret_2 = printf("%.4S\n", L"我是一只猫。");
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("%.0p, %.p\n", 0, 0); // test 74 - undefined behavior
	//    ret_2 = printf("%.0p, %.p\n", 0, 0);
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("%.p, %.0p\n", 0, 0); // test 79 - undefined behavior
	//    ret_2 = printf("%.p, %.0p\n", 0, 0);
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("{%05.s}\n", 0); // test 79 - undefined behavior
	//    ret_2 = printf("{%05.s}\n", 0);
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("{%05.%}\n", 0); // test 79 - undefined behavior
	//    ret_2 = printf("{%05.%}\n", 0);
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("{%05.Z}\n", 0); // test 79 - undefined behavior
	//    ret_2 = printf("{%05.Z}\n", 0);
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("{%05.S}\n", L"42 c est cool"); // test 79 - undefined behavior
	//    ret_2 = printf("{%05.S}\n", L"42 c est cool");
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	ret_1 = ft_printf("% ");
	   ret_2 = printf("% ");
	printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);
	return (0);
}
