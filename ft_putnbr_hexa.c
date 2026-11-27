/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboel-ma <aboel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 00:48:33 by aboel-ma          #+#    #+#             */
/*   Updated: 2026/11/27 15:22:08 by aboel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa(unsigned long n, char c)
{
	int		count;
	int		result;
	char	*base;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (n > 15)
	{
		result = ft_putnbr_hexa(n / 16, c);
		if (result == -1)
 			return (-1);
		count = result;
	}
	result = ft_putchar(base[(n % 16)]);
	if (result == -1)
 		return (-1);
	count = count + result;
	return (count);
}
