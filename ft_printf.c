/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:02:27 by tomamart          #+#    #+#             */
/*   Updated: 2025/05/27 10:41:15 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(char const *format, ...)
{
	int		i;
	int		total;
	va_list	args;

	va_start(args, format);
	i = 0;
	total = 0;
	if (!format)
		return (-1);
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
			total += ft_handle_format(format[i], args);
		}
		i++;
	}
	va_end(args);
	return (total);
}
