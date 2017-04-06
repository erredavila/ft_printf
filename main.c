/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:13:35 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/06 15:48:24 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <ft_printf.h>
#include <wchar.h>
#include <locale.h>

int		main()
{
	/*
	char *red = "\033[31m";
	char *eoc = "\033[0m";
	printf("%s RED %s", red, eoc); 
	*/

/*
**	printf("%[flags][width][.precision][length]");
**	printf("%['-' '+' ' ' '0' '#'][10][4][hh, h, l , ll, j, z]");
**	flags '+', ' ', '0', '#' results in undefined behavior with 's' conversion specifier
*/

	/*
	printf("ESCAPED '%%'\n");
	printf("A: [%%]\n");
	ft_printf("R: [%%]\n");
	printf("A: [%010%]\n");
	ft_printf("R: [%010%]\n");
	*/

	//printf("\n\n%O\n\n", 42);
	/*
	char *s = "Hello";
	printf("STRINGS:\n");
	// flags '+', ' ', '0', '#' results in undefined behavior with 's' conversion specifier
	// normal	
	printf("A: [%s] [%s]\n", s, s);
	ft_printf("R: [%s] [%s]\n", s, s);
	// '-' flag	
	printf("A: [%-10s]\n", s);
	ft_printf("R: [%-10s]\n", s);
	// width
	printf("A: [%10s]\n", s);
	ft_printf("R: [%10s]\n", s);
	// precision
	printf("A: [%.4s]\n", s);
	ft_printf("R: [%.4s]\n", s);
	*/

	/*
	printf("CHARACTERS:\n");
	// flags '#', '0', '+', ' ' results in undefined behavior with 'x' conversion specifier
	printf("A: [%c]\t[%c]\n", 'A', 65);
	ft_printf("R: [%c]\t[%c]\n", 'A', 65);
	printf("[%10.5c]\n", 'a');
	ft_printf("[%10.5c]\n", 'a');
	*/

	/*
	// Strange case
	printf("%#6o\n", 2500);
	ft_printf("%#6o\n", 2500);
	printf("@moulitest: [%#.0o] [%#.0x]\n", 42, 42);
	ft_printf("@moulitest: [%#.0o] [%#.0x]\n", 42, 42);
	printf("%#.0o\n", 0);
	ft_printf("%#.0o\n", 0);
	printf("%#x\n", 0);
	ft_printf("%#x\n", 0);
	*/

	/*
	setlocale(LC_ALL, "en_US.UTF-8");
	//setlocale(LC_ALL, "");
	wchar_t t = 8364;
	printf("%lc\n", t);
	ft_printf("%lc\n", t);
	//wchar_t *s = L"€€€";
	wchar_t v = L'🐼';
	ft_printf("A: [%lc]\n", v);
	printf("R: [%lc]\n", v);
	wchar_t *a = L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B";
	ft_printf("{%030S}", a);
	*/

	/*
	int n = 0;
	printf("HEX (x, X):\n");
	// flags '+', ' ', '0' results in undefined behavior with 'x' conversion specifier
	//printf("A: [%#x]\t[%X]\n", n, n);
	//ft_printf("R: [%#x]\t[%X]\n", n, n);
	printf("[%#x]\n", n);
	ft_printf("[%#x]\n", n);
	//n = printf("%010x\n", 542);
	//printf("ORIGINAL: %d\n", n);
	//n = ft_printf("%010x\n", 542);
	//printf("MINE: %d\n", n);
	*/

	/*
	int n = 0;
	printf("OCTAL (o, O):\n");
	// flags '+', ' ', '0' results in undefined behavior with 'x' conversion specifier
	//printf("A: [%o]\n", n);
	//ft_printf("R: [%o]\n", n);
	printf("A: @moulitest: [%#0.x] [%#.0x]\n", n, n);
	ft_printf("R: @moulitest: [%#0.x] [%#.0x]\n", n, n);
	int a = printf("A: @moulitest: [%#.o] [%#.0o]\n", n, n);
	int b = ft_printf("R: @moulitest: [%#.o] [%#.0o]\n", n, n);
	printf("ORIGINAL: %d\n", a);
	printf("MINE: %d\n", b);
	*/

	/*
	int n = 42;
	printf("INTEGERS:\n");
	int a = printf("A: [%10.5d]\n", n);
	int b = ft_printf("R: [%05d]\n", n);
	printf("ORIGINAL: %d\n", a);
	printf("MINE: %d\n", b);
	*/

	/*
	int n = 42;
	printf("UNSIGNED INTEGERS:\n");
	// flags '#', '+', ' ' results in undefined behavior with 'x' conversion specifier
	int a = printf("A: [%.0u]\n", n);
	int b = ft_printf("R: [%.0u]\n", n);
	printf("ORIGINAL: %d\n", a);
	printf("MINE: %d\n", b);
	*/

	/*
	size_t test;
	test = 42;
	printf("TST: %lu\n", sizeof(test));
	*/

	/*
	printf("POINTERS:\n");
	int a;
	int	*b;	
	a = 42;
	b = &a;
	int x = printf("a: %d\tb: [%20p]\n", a, b);
	int y = ft_printf("a: %d\tb: [%20p]\n", a, b);
	printf("ORIGINAL: %d\n", x);
	printf("MINE: %d\n", y);
	*/

	/*
	printf("{%#.o} {%#.x}\n", 0, 0);
	ft_printf("{%#.o} {%#.x}", 0, 0);
	*/

	int n = 42;
	printf("%#o\n", n);
	printf("-----------------\n");
	ft_printf("%#o\n", n);
	printf("-----------------\n");
	printf("%#.3o\n", n);
	printf("-----------------\n");
	ft_printf("%#.3o\n", n);
	printf("-----------------\n");
	printf("%#.3x\n", n);
	printf("-----------------\n");
	ft_printf("%#.3x\n", n);

	setlocale(LC_ALL, "en_US.UTF-8");
/*
	setlocale(LC_ALL, "en_US.UTF-8");
	wchar_t test1 = L'ÁM-^L´';
	wchar_t test4 = L'\x2126';
	wchar_t test2 = L'ÊM-^ZM-^V';
	wchar_t test3 = L'ÿ≠';
	printf("-----------------\n");
	printf("%C\n", test4);
	ft_printf("%C\n", test4);
	printf("%lc, %lc\n", test2, test3);
	ft_printf("%lc, %lc\n", test2, test3);
	*/

	return (0);
}
