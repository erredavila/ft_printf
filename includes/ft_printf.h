/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:31:05 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/06 14:13:02 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>

// Remove! Only for testing
# include <stdio.h>

typedef	struct		s_flags
{
	int				left_align;
	int				force_sign;
	int				blank;
	int				pad_zero;
	int				prefix;
	int				got_width;
	int				got_precision;
	int				width;
	int				precision;
	enum {
		empty,
		hh,
		h,
		l,
		ll,
		j,
		z
	}				length;
}					t_flags;

int					ft_printf_handle_percent(char c, va_list args, t_flags flags);
int					ft_printf_handle_str(char c, va_list args, t_flags flags);
int					ft_printf_handle_wstr(char c, va_list args, t_flags flags);
int					ft_printf_handle_char(char c, va_list args, t_flags flags);
int					ft_printf_handle_wchar(char c, va_list args, t_flags flags);
int					ft_printf_handle_int(char c, va_list args, t_flags flags);
int					ft_printf_handle_hex(char c, va_list args, t_flags flags);
int					ft_printf_handle_octal(char c, va_list args, t_flags flags);
int					ft_printf_handle_unsigned(char c, va_list args, t_flags flags);
int					ft_printf_handle_ptr(char c, va_list args, t_flags flags);
int					ft_printf_handle_null(char c, va_list args, t_flags flags);

int					ft_printf_handle_uint(size_t num, t_flags flags, char *base, char *prefix);
int					ft_printf_calc_nbrstrlen(size_t num, char *base, char *prefix, t_flags flags);
void				ft_putnbrbp(uintmax_t num, int len, char *base, t_flags flags);

void				add_padding(int min, int max, char c);
int					force_prefix(size_t num, char *base, t_flags flags, char *prefix);
size_t				parse_uint_length(va_list args, t_flags flags);
size_t				parse_sint_length(va_list args, t_flags flags);

char				*ft_parse_flags(char **format, t_flags *flags);
char				*ft_parse_width(char **format, va_list args, t_flags *flags);
char				*ft_parse_precision(char **format, va_list args, t_flags *flags);
char				*ft_parse_length(char **format, t_flags *flags);

typedef	int			(*t_handler)(char, va_list, t_flags);
t_handler			get_handler(char c);
#endif
