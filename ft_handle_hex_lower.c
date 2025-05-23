#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int ft_handle_hex_lower(va_list args)
{
	unsigned int	x;
				
	x = va_arg(args, unsigned int);
	return (ft_puthex_base_count(x, "0123456789abcdef"));
}