/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_octal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:38:58 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/06 14:55:53 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

static int		ft_printf_inner_octal(uintmax_t num, t_flags flags, char *base, char *prefix)
{
	int	len;
	int	numstrlen;

	if (flags.got_precision)
		flags.pad_zero = 0;
	len = ft_num_length_base(num, base);
	numstrlen = ft_printf_calc_nbrstrlen(num, base, prefix, flags);
	if (flags.got_width && !flags.left_align && flags.pad_zero)
	{
		if (flags.prefix)
			flags.precision = ft_max(flags.width - ft_strlen(prefix), len);
		else
			flags.precision = ft_max(flags.width, len);
		flags.got_precision = 1;
	}
	if (flags.got_width && !flags.left_align && !flags.pad_zero)
		add_padding(numstrlen, flags.width, ' ');
	if (flags.prefix && num)
		ft_putstr(prefix);
	if (flags.prefix && !num && !ft_strcmp(base, "01234567") && flags.got_precision)
	{
		ft_putstr(prefix);
		numstrlen++;
	}
	ft_putnbrbp(num, len, base, flags);
	if (flags.got_width && flags.left_align)
		add_padding(numstrlen, flags.width, ' ');
	return (flags.got_width ? ft_max(numstrlen, flags.width) : numstrlen);
}

int		ft_printf_handle_octal(char c, va_list args, t_flags flags)
{
	uintmax_t	num;
	int			len;

	if (c == 'O')
		flags.length = l;
	num = parse_uint_length(args, flags);
	len = ft_num_length_base(num, "01234567");
	if (flags.precision > len)
		flags.prefix = 0;
	return (ft_printf_inner_octal(num, flags, "01234567", "0"));
}
