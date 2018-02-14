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
#include "inc/ft_printf.h"

int		main(void)
{
	setlocale(LC_ALL, "");
	wchar_t *value = L"ЇЇЇ";
	wchar_t *value2 = L"我是一只猫。";
	wchar_t value3 = L'我';
	int 	*str;
	int		ret_1;
	int		ret_2;
	str = &ret_1;
	// ret_1 = ft_printf("% Zoooo\n");
	//    ret_2 = printf("% Zoooo\n");

	// ret_1 = ft_printf("{%}\n");
	//    ret_2 = printf("{%}\n");

	// ft_printf("@moulitest: %.o %.0o\n", 0, 0);
	//    printf("@moulitest: %.o %.0o\n", 0, 0);

	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);
	//    printf("Bla Bla %#05x\n", 123);

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

	// ret_1 = ft_printf("% ");
	//    ret_2 = printf("% ");
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("%ll#x\n", 9223372036854775807);
	//    ret_2 = printf("%ll#x\n", 9223372036854775807);
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("%p\n", 0);
	//    ret_2 = printf("%p\n", 0);
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("{%-12p}\n", &strlen);
	//    ret_2 = printf("{%-12p}\n", &strlen);
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("%hhC, %hhC\n", 0, L'米');
	//    ret_2 = printf("%hhC, %hhC\n", 0, L'米');
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	// ret_1 = ft_printf("%010%\n");
	//    ret_2 = printf("%010%\n");
	// printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	ret_1 = ft_printf("|%#-10.o|\n", 0);
	   ret_2 = printf("|%#-10.o|\n", 0);
	printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

	ret_1 = ft_printf("|%#10x|\n", 0);
	   ret_2 = printf("|%#10x|\n", 0);
	printf("\nret_1 = %i\nret_2 = %i\n", ret_1, ret_2);

// #include <string.h>

// int main(void)
// {
// 	ft_printf("\n");
// 	ft_printf("%%\n");
// 	ft_printf("%d\n", 42);
// 	ft_printf("%d%d\n", 42, 41);
// 	ft_printf("%d%d%d\n", 42, 43, 44);
// 	ft_printf("%ld\n", 2147483647);
// 	ft_printf("%lld\n", 9223372036854775807);
// 	ft_printf("%x\n", 505);
// 	ft_printf("%X\n", 505);
// 	ft_printf("%p\n", &ft_printf);
// 	ft_printf("%20.15d\n", 54321);
// 	ft_printf("%-10d\n", 3);
// 	ft_printf("% d\n", 3);
// 	ft_printf("%+d\n", 3);
// 	ft_printf("%010d\n", 1);
// 	ft_printf("%hhd\n", 0);
// 	ft_printf("%jd\n", 9223372036854775807);
// 	ft_printf("%zd\n", 4294967295);
// 	ft_printf("%\n");
// 	ft_printf("%U\n", 4294967295);
// 	ft_printf("%u\n", 4294967295);
// 	ft_printf("%o\n", 40);
// 	ft_printf("%%#08x\n", 42);
// 	ft_printf("%x\n", 1000);
// 	ft_printf("%#X\n", 1000);
// 	ft_printf("%s\n", NULL);
// 	ft_printf("%S\n", L"ݗݜशব");
// 	ft_printf("%s%s\n", "test", "test");
// 	ft_printf("%s%s%s\n", "test", "test", "test");
// 	ft_printf("%C\n", 15000);
// 	// while (1);
// 	return (0);
// }

	return (0);
}
