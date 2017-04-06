#include <libft.h>

void	ft_putnstr(const char *s, size_t len)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (*s && i < len)
		{
			ft_putchar(*s);
			s++;
			i++;
		}
	}
}
