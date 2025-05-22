#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int handle_hex_upper(va_list args)
{
	unsigned int	X;
				
	X = va_arg(args, unsigned int);
	return (ft_puthex_base_count(X, "0123456789ABCDEF"));
}