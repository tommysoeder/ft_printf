/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomamart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:58:25 by tomamart          #+#    #+#             */
/*   Updated: 2025/04/09 13:01:21 by tomamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int n)
{
	if ((n >= 48 && n <= 57) || (n >= 65 && n <= 90) || (n >= 97 && n <= 122))
		return (1);
	else
		return (0);
}
