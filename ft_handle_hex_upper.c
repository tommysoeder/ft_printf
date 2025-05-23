/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <tomamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:32:39 by tomamart          #+#    #+#             */
/*   Updated: 2025/05/23 15:10:53 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_handle_hex_upper(va_list args)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	return (ft_puthex_base_count(x, "0123456789ABCDEF"));
}
