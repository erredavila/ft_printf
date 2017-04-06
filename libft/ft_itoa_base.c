/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:16:49 by rdavila           #+#    #+#             */
/*   Updated: 2017/03/22 14:14:45 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	get_len(int value, int base)
{
	int	len;

	len = 0;
	if (!value)
		return (1);
	if (value < 0 && base == 10)
		len++;
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(int value, int base)
{
	char	*ret;
	int		neg;
	int		len;
	long	value_cpy;
	char	buff[16] = "0123456789ABCDEF";

	neg = 0;
	len = get_len(value, base);
	ret = (char *)malloc(sizeof(*ret) * (len + 1));
	ret[len] = '\0';
	value_cpy = value;
	if (value_cpy < 0)
	{
		if (base == 10)
			neg = 1;
		value_cpy *= -1;
	}
	while (--len)
	{
		ret[len] = buff[value_cpy % base];
		value_cpy /= base;
	}
	if (neg)
		ret[len] = '-';
	else
		ret[len] = buff[value_cpy % base];
	return (ret);
}
