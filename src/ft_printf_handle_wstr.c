/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_wstr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <rdavila@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 10:34:53 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/05 20:53:59 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

static void	ft_putnwstr(wchar_t *s, int len)
{
	int i;

	i = 0;
	while (*s && i < len)
	{
		if (*s <= 0x7F)
			i++;
		else if (*s <= 0x7FF)
			i += 2;
		else if (*s <= 0xFFFF)
			i += 3;
		else if (*s <= 0x10FFFF)
			i += 4;
		if (i <= len)
			ft_putwchar(*s);
		s++;
	}
}

static int	ft_wstrnlen(wchar_t *s, int precision)
{
	int		i;

	i = 0;
	while (*s && precision > 0)
	{
		if (*s <= 0x7F)
		{
			precision--;
			i++;
		}
		else if (*s <= 0x7FF && precision >= 2)
		{
			precision -= 2;
			i += 2;
		}
		else if (*s <= 0xFFFF && precision >= 3)
		{
			precision -= 3;
			i += 3;
		}
		else if (*s <= 0x10FFFF && precision >= 4)
		{
			precision -= 4;
			i += 4;
		}
		s++;
	}
	return (i);
}

static int	ft_wstrlen(wchar_t *s)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s <= 0x7F)
			i++;
		else if (*s <= 0x7FF)
			i += 2;
		else if (*s <= 0xFFFF)
			i += 3;
		else if (*s <= 0x10FFFF)
			i += 4;
		s++;
	}
	return (i);
}

int		ft_printf_handle_wstr(char c, va_list args, t_flags flags)
{
	wchar_t	*s;
	int		len;

	(void)c;
	(void)flags;
	s = va_arg(args, wchar_t *);
	if (!s)
		s = L"(null)";
	len = ft_wstrlen(s);
	if (flags.got_precision)
		len = ft_wstrnlen(s, flags.precision);
	if (flags.got_width && !flags.left_align)
		add_padding(len, flags.width, flags.pad_zero ? '0' : ' ');
	ft_putnwstr(s, len);
	if (flags.got_width && flags.left_align)
		add_padding(len, flags.width, flags.pad_zero ? '0' : ' ');
	if (flags.got_width)
		return (ft_max(flags.width, len));
	return (len);
}
