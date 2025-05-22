#include <unistd.h>

int	ft_puthex_base_count(unsigned int n, char *base)
{
	int count = 0;

	if (n >= 16)
		count += ft_puthex_base_count(n / 16, base);
	write(1, &base[n % 16], 1);
	return (count + 1);
}
