/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:32:53 by tomamart          #+#    #+#             */
/*   Updated: 2025/05/23 15:31:07 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>

int	ft_puthex_ptr(unsigned long n)
{
	int		count;
	char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex_ptr(n / 16);
	write(1, &hex[n % 16], 1);
	return (count + 1);
}

int	ft_handle_pointer(va_list args)
{
	void			*ptr;
	unsigned long	addr;
	int				count;

	ptr = (void *)va_arg(args, void *);
	if (!ptr)
		return (write(1, "0x0", 3));
	addr = (unsigned long)ptr;
	count = write(1, "0x", 2);
	count += ft_puthex_ptr(addr);
	return (count);
}
