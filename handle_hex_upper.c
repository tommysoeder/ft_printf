#include <unistd.h>
#include <stdarg.h>

int	ft_puthex_base_count(unsigned int n, char *base);

int handle_hex_upper(va_list args)
{
	unsigned int	X;
				
	X = va_arg(args, unsigned int);
	return (ft_puthex_base_count(X, "0123456789ABCDEF"));
}