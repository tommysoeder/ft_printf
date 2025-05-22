#include <unistd.h>
#include <stdarg.h>

int	handle_string(va_list args)
{
	char *str;
	int	count;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	count = 0;
	while (str[count])
		write(1, &str[count++], 1);
	return(count);
}