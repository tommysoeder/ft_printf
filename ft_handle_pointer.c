#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>

int	ft_puthex_ptr(unsigned long n)
{
	int count = 0;
	char *hex = "0123456789abcdef";

	if (n >= 16)
		count += ft_puthex_ptr(n / 16);
	write(1, &hex[n % 16], 1);
	return (count + 1);
}

int	ft_handle_pointer(va_list args)
{
	void	*ptr;
	unsigned long	addr;
	int	count;
	
	count = 0;
	ptr = va_arg(args, void *);
	addr = (unsigned long)ptr;
	write(1, "0x", 2);
	count += 2 + ft_puthex_ptr(addr);
	return(count);
}