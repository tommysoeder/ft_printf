#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int ft_printf(const char *format, ...);
int	handle_string(va_list args);
int	handle_char(va_list args);
int	handle_integer(va_list args);
int	ft_putnbr_count(unsigned int n);
int	handle_unsigned(va_list args);
int	ft_putunbr_count(unsigned int n);
int handle_hex_lower(va_list args);
int	ft_puthex_base_count(unsigned int n, char *base);
int handle_hex_upper(va_list args);

#endif