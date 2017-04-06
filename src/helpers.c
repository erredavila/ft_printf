/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:41:24 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/06 14:13:12 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int	force_prefix(size_t num, char *base, t_flags flags, char *prefix)
{
	int		len;
	int		cut;

	cut = ft_strlen(prefix);
	len = ft_printf_calc_nbrstrlen(num, base, prefix, flags) + cut;
	if (flags.got_width && !flags.left_align && !flags.pad_zero)
	{
		add_padding(len, flags.width, ' ');
		cut += ft_max(flags.width - len, 0);
		flags.got_width = 0;
	}
	else if (flags.got_width)
		flags.width -= cut;
	ft_putstr(prefix);
	return (ft_printf_handle_uint(num, flags, base, NULL) + cut);
}

int	ft_printf_calc_nbrstrlen(uintmax_t num, char *base, char *prefix, t_flags flags)
{
	int	num_len;
	int	numstrlen;

	num_len = ft_num_length_base(num, base);
	if (!num && flags.got_precision && !flags.precision)
		numstrlen = 0;
	else if (flags.got_precision)
		numstrlen = ft_max(num_len, flags.precision);
	else
		numstrlen = num_len;
	if (flags.prefix && prefix && num)
		numstrlen += ft_strlen(prefix);
	return (numstrlen);
}

void	ft_putnbrbp(uintmax_t num, int len, char *base, t_flags flags)
{
	if (flags.got_precision)
		add_padding(len, flags.precision, '0');
	if (!num && flags.got_precision && !flags.precision)
		return ;
	else
		ft_putnbrbase(num, base);
}

int		ft_printf_handle_uint(uintmax_t num, t_flags flags, char *base, char *prefix)
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
