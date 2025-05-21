/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:02:27 by tomamart          #+#    #+#             */
/*   Updated: 2025/05/21 21:57:19 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putnbr_count(int n)
{
	int		count = 0;
	long	nb = n;
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	if (nb >= 10)
		count += ft_putnbr_count(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	return (count + 1);
}

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
int	ft_puthex_ptr(unsigned long n)
{
	int count = 0;
	char *hex = "0123456789abcdef";

	if (n >= 16)
		count += ft_puthex_ptr(n / 16);
	write(1, &hex[n % 16], 1);
	return (count + 1);
}

int	ft_puthex_base_count(unsigned int n, char *base)
{
	int count = 0;

	if (n >= 16)
		count += ft_puthex_base_count(n / 16, base);
	write(1, &base[n % 16], 1);
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
			{
				char *str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				int j = 0;
				while (str[j])
				{
					write(1, &str[j], 1);
					j++;
				}
				total += j;
			}
			else if(format[i] == 'c')
			{
				char	c;
				
				c = (char)va_arg(args, int);
				ft_putchar_fd(c, 1);
				total++;
			}
			else if(format[i] == 'd' || format[i] == 'i')
			{
				int	d;
				
				d = va_arg(args, int);
				total += ft_putnbr_count(d);
			}
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
			{
				unsigned int	u;
				
				u = va_arg(args, unsigned int);
				total += ft_putunbr_count(u);
			}
			else if(format[i] == 'x')
			{
				unsigned int	x;
				
				x = va_arg(args, unsigned int);
				total += ft_puthex_base_count(x, "0123456789abcdef");
			}
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
