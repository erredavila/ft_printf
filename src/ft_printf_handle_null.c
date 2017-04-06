/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_null.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <rdavila@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 18:34:03 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/05 19:04:10 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		ft_printf_handle_null(char c, va_list args, t_flags flags)
{
	(void)args;
	if (flags.got_width && !flags.left_align)
		add_padding(1, flags.width, (flags.pad_zero) ? '0' : ' ');
	ft_putchar(c);
	if (flags.got_width && flags.left_align)
		add_padding(1, flags.width, (flags.pad_zero) ? '0' : ' ');
	if (flags.got_width)
		return (ft_max(flags.width, 1));
	return (1);
}
