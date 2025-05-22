/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:02:27 by tomamart          #+#    #+#             */
/*   Updated: 2025/05/22 18:50:24 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_puthex_ptr(unsigned long n)
{
	int count = 0;
	char *hex = "0123456789abcdef";

	if (n >= 16)
		count += ft_puthex_ptr(n / 16);
	write(1, &hex[n % 16], 1);
	return (count + 1);
}

int	ft_printf(char const *format, ...)
{
	int	i;
	int	total;
	va_list	args;
	va_start(args, format);

	i = 0;
	total = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			total++;
		}
		else
		{
			i++;
			if(format[i] == 's')
				total += handle_string(args);
			else if(format[i] == 'c')
				total += handle_char(args);
			else if(format[i] == 'd' || format[i] == 'i')
				total += handle_integer(args);
			else if(format[i] == 'p')
			{
				void	*ptr;
				unsigned long	addr;
				
				ptr = va_arg(args, void *);
				addr = (unsigned long)ptr;
				write(1, "0x", 2);
				total += 2 + ft_puthex_ptr(addr);
			}
			else if(format[i] == 'u')
				total += handle_unsigned(args);
			else if(format[i] == 'x')
				total += handle_hex_lower(args);
			else if(format[i] == 'X')
			{
				unsigned int	X;
				
				X = va_arg(args, unsigned int);
				total += ft_puthex_base_count(X, "0123456789ABCDEF");
			}
			else if(format[i] == '%')
			{
				write(1, "%", 1);
				total++;
			}
		}
		i++;
	}
	va_end(args);
	return (total);
}
