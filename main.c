/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:13:35 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/12 11:37:28 by rdavila          ###   ########.fr       */
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

	printf("-----------------\n");
	printf("ESCAPED (%%)\n");
	printf("-----------------\n");
	printf("A: [%%]\n");
	ft_printf("R: [%%]\n");
	printf("A: [%010%]\n");
	ft_printf("R: [%010%]\n");

	printf("-----------------\n");
	printf("STRINGS (s):\n");
	printf("-----------------\n");
	// flags '+', ' ', '0', '#' results in undefined behavior with 's' conversion specifier
	char *s = "Hello";
	// normal	
	printf("A: [%10.2s] [%5.1s]\n", s, s);
	ft_printf("R: [%10.2s] [%5.1s]\n", s, s);
	// '-' flag	
	printf("A: [%-10s]\n", s);
	ft_printf("R: [%-10s]\n", s);
	// width
	printf("A: [%10s]\n", s);
	ft_printf("R: [%10s]\n", s);
	// precision
	printf("A: [%.4s]\n", s);
	ft_printf("R: [%.4s]\n", s);

	printf("-----------------\n");
	printf("CHARACTERS (c):\n");
	printf("-----------------\n");
	// flags '#', '0', '+', ' ' results in undefined behavior with 'x' conversion specifier
	printf("A: [%c]\t[%c]\n", 'A', 65);
	ft_printf("R: [%c]\t[%c]\n", 'A', 65);
	printf("[%5c]\n", 'a');
	ft_printf("[%5c]\n", 'a');

	printf("-----------------\n");
	printf("WIDE CHARACTERS (lc, ls, C, S):\n");
	printf("-----------------\n");
	setlocale(LC_ALL, "en_US.UTF-8");
	wchar_t g = 8364;
	wchar_t panda = L'🐼';
	printf("%lc\n", g);
	ft_printf("%lc\n", g);
	printf("%C\n", panda);
	ft_printf("%C\n", panda);
	wchar_t *t = L"Це український тест для широких символів";
	ft_printf("A: [%ls]\n", t);
	printf("R: [%ls]\n", t);

	printf("-----------------\n");
	printf("HEX (x, X):\n");
	printf("-----------------\n");
	int n = 42;
	// flags '+', ' ', '0' results in undefined behavior with 'x' conversion specifier
	printf("A: [%x] [%X]\n", n, n);
	ft_printf("R: [%x] [%X]\n", n, n);
	printf("[%#10x]\n", n);
	ft_printf("[%#10x]\n", n);
	printf("[%-#10x]\n", n);
	ft_printf("[%-#10x]\n", n);
	printf("A: [%010x]\n", 542);
	ft_printf("R: [%010x]\n", 542);

	printf("-----------------\n");
	printf("OCTAL (o, O):\n");
	printf("-----------------\n");
	int m = 42;
	// flags '+', ' ', '0' results in undefined behavior with 'x' conversion specifier
	printf("A: [%o]\n", m);
	ft_printf("R: [%o]\n", m);
	printf("A: [%#0o] [%5o]\n", m, m);
	ft_printf("R: [%#0o] [%5o]\n", m, m);
	printf("A: [%#.6o] [%#.6o]\n", m, m);
	ft_printf("R: [%#.6o] [%#.6o]\n", m, m);
	printf("A: [%-10o]\n", m);
	ft_printf("R: [%-10o]\n", m);

	printf("-----------------\n");
	printf("PREFIX IN OCTAL AND HEX:\n");
	printf("-----------------\n");
	printf("[%#10o]\n", 2500);
	ft_printf("[%#10o]\n", 2500);
	printf("[%-#10o]\n", 2500);
	ft_printf("[%-#10o]\n", 2500);
	printf("@moulitest: [%#.o] [%#.x]\n", 0, 0);
	ft_printf("@moulitest: [%#.o] [%#.x]\n", 0, 0);

	printf("-----------------\n");
	printf("INTEGERS (d, D, i):\n");
	printf("-----------------\n");
	int o = 42;
	printf("A: [%d]\n", o);
	ft_printf("R: [%d]\n", o);
	printf("A: [%10d]\n", o);
	ft_printf("R: [%10d]\n", o);
	printf("A: [%-10.5d]\n", o);
	ft_printf("R: [%-10.5d]\n", o);

	printf("-----------------\n");
	printf("UNSIGNED INTEGERS (u, U):\n");
	printf("-----------------\n");
	unsigned int l = 42;
	// flags '#', '+', ' ' results in undefined behavior with 'x' conversion specifier
	printf("A: [%u]\n", l);
	ft_printf("R: [%u]\n", l);
	printf("A: [%10u]\n", l);
	ft_printf("R: [%10u]\n", l);
	printf("A: [%-10.5u]\n", l);
	ft_printf("R: [%-10.5u]\n", l);

	printf("-----------------\n");
	printf("POINTERS (p):\n");
	printf("-----------------\n");
	int a;
	int	*b;	
	a = 42;
	b = &a;
	printf("num: %d\tptr: [%p]\n", a, b);
	ft_printf("num: %d\tptr: [%p]\n", a, b);
	printf("num: %d\tptr: [%20p]\n", a, b);
	ft_printf("num: %d\tptr: [%20p]\n", a, b);

	/*
	size_t a = 4294967296;
	printf("Undefined behaviors\n");
	ft_printf("MINE: %-010s is a string\n", "this");
	printf("ORIG: this       is a string\n");
	ft_printf("MINE: %010s is a string\n", "this");
	printf("ORIG: 000000this is a string\n");
	ft_printf("MINE: %zhd\n", a);
	printf("ORIG: %zhd\n", a);
	*/
	return (0);
}
