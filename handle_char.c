#include <unistd.h>
#include <stdarg.h>

int	handle_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	return(1);
}