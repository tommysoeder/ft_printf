
#include <stdarg.h>
#include <unistd.h>

int	ft_putunbr_count(unsigned int n)
{
	int count = 0;
	char c;

	if (n >= 10)
		count += ft_putunbr_count(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (count + 1);
}

int	handle_unsigned(va_list args)
{
	unsigned int	u;
				
	u = va_arg(args, unsigned int);
	return (ft_putunbr_count(u));
}
