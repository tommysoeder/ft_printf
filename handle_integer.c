#include "libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_putnbr_count(int n)
{
	int		count = 0;
	long	nb = n;
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	if (nb >= 10)
		count += ft_putnbr_count(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	handle_integer(va_list args)
{
	int	d;

	d = va_arg(args, int);
	return(ft_putnbr_count(d));
}