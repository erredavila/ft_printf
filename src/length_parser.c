#include <libft.h>
#include <ft_printf.h>

uintmax_t	parse_uint_length(va_list args, t_flags flags)
{
	uintmax_t	nbr;

	nbr = va_arg(args, uintmax_t);
	if (flags.length == hh)
		nbr = (unsigned char)nbr;
	else if (flags.length == h)
		nbr = (unsigned short)nbr;
	else if (flags.length == l)
		nbr = (unsigned long)nbr;
	else if (flags.length == ll)
		nbr = (unsigned long long)nbr;
	else if (flags.length == j)
		nbr = (uintmax_t)nbr;
	else if (flags.length == z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

size_t		parse_sint_length(va_list args, t_flags flags)
{
	intmax_t	nbr;

	nbr = va_arg(args, intmax_t);
	if (flags.length == hh)
		nbr = (signed char)nbr;
	else if (flags.length == h)
		nbr = (short)nbr;
	else if (flags.length == l)
		nbr = (long)nbr;
	else if (flags.length == ll)
		nbr = (long long)nbr;
	else if (flags.length == j)
		nbr = (intmax_t)nbr;
	else if (flags.length == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}
